#include "Entity.h"
#include <vector>

using namespace std;

Entity::Entity(char* textureUrl)
{
	Parent = nullptr;

	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);

	boundingBox.SetSize(Vector2(-60, -60));

	if (textureUrl != nullptr)
	{
		char tempChar[32];
		strcpy(tempChar, "./textures/");
		strcat(tempChar, textureUrl);
		strcat(tempChar, ".png");
		texture = new Texture(tempChar);
	}
	else
	{
		texture = nullptr;
	}
}

Entity::~Entity()
{
}

void Entity::setParent(Entity* parent)
{
	Parent = parent;
}

void Entity::setChild(Entity* child)
{
	children.push_back(child);
}

void Entity::updateGlobalTransform()
{
	if (Parent != nullptr)
	{
		GlobalTrasform = Parent->GlobalTrasform * localTransform;
	}
	else
	{
		GlobalTrasform = localTransform;
	}
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->updateGlobalTransform();
	}
}

Collider& Entity::GetCollider()
{
	return m_Collider;
}

Vector2 Entity::GetPosition()
{
	Vector2 pos;

	pos.x = GlobalTrasform.m[6];
	pos.y = GlobalTrasform.m[7];

	return pos;
}

void Entity::SetPosition(float x, float y)
{
	localTransform.m[6] = x;
	localTransform.m[7] = y;

	updateGlobalTransform();
}

void Entity::Update(float deltaTime)
{

}

void Entity::Draw(Renderer2D* renderer2D)
{
	if (texture)
	{
		renderer2D->drawSpriteTransformed3x3(texture, GlobalTrasform);
	}

	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Draw(renderer2D);
	}
}


void Entity::SetType(Types types)
{
	this->types = types;
}

Types Entity::GetType()
{
	return types;
}





















// SAT
Vector2 Entity::Project(Vector2& a, Vector2& b)
{
	Vector2 result;

	result.x = a.dot(b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2)) * b.x;
	result.y = a.dot(b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2)) * b.y;

	return result;
}

float MinV(vector<float> x)
{
	float retVal = x[0];

	for (int i = 1; i < x.size(); i++)
	{
		if (x[i] < retVal)
		{
			retVal = x[i];
		}
	}

	return retVal;
}

float MaxV(vector<float> x)
{
	float retVal = x[0];

	for (int i = 1; i < x.size(); i++)
	{
		if (x[i] > retVal)
		{
			retVal = x[i];
		}
	}

	return retVal;
}

bool Entity::IsColliding(Entity* a, Entity* b)
{
	rect rcA = a->boundingBox;
	rect rcB = b->boundingBox;

	Vector2 aUR = rcA.UpperRight + a->GetPosition();
	Vector2 aUL = rcA.UpperLeft + a->GetPosition();
	Vector2 aLR = rcA.LowerRight + a->GetPosition();
	Vector2 aLL = rcA.LowerLeft + a->GetPosition();

	Vector2 bUR = rcB.UpperRight + b->GetPosition();
	Vector2 bUL = rcB.UpperLeft + b->GetPosition();
	Vector2 bLR = rcB.LowerRight + b->GetPosition();
	Vector2 bLL = rcB.LowerLeft + b->GetPosition();

	float aMax = 0;
	float aMin = 0;
	float bMax = 0;
	float bMin = 0;

	Vector2 a1 = aUR - aUL;
	Vector2 a2 = aUR - aLR;
	Vector2 a3 = bUL - bLL;
	Vector2 a4 = bUL - bUR;

	vector<Vector2> axes;
	axes.push_back(a1);
	axes.push_back(a2);
	axes.push_back(a3);
	axes.push_back(a4);

	for (int i = 0; i  < axes.size(); i++)
	{
		Vector2 aURProj = Project(aUR, axes[i]);
		Vector2 aULProj = Project(aUL, axes[i]);
		Vector2 aLRProj = Project(aLR, axes[i]);
		Vector2 aLLProj = Project(aLL, axes[i]);
		
		Vector2 bURProj = Project(bUR, axes[i]);
		Vector2 bULProj = Project(bUL, axes[i]);
		Vector2 bLRProj = Project(bLR, axes[i]);
		Vector2 bLLProj = Project(bLL, axes[i]);

		float aURScalar = aURProj.dot(axes[i]);
		float aULScalar = aULProj.dot(axes[i]);
		float aLRScalar = aLRProj.dot(axes[i]);
		float aLLScalar = aLLProj.dot(axes[i]);

		float bURScalar = bURProj.dot(axes[i]);
		float bULScalar = bULProj.dot(axes[i]);
		float bLRScalar = bLRProj.dot(axes[i]);
		float bLLScalar = bLLProj.dot(axes[i]);

		vector<float> aScalars;
		aScalars.push_back(aURScalar);
		aScalars.push_back(aULScalar);
		aScalars.push_back(aLRScalar);
		aScalars.push_back(aLLScalar);
		aMin = MinV(aScalars);
		aMax = MaxV(aScalars);

		vector<float> bScalars;
		bScalars.push_back(bURScalar);
		bScalars.push_back(bULScalar);
		bScalars.push_back(bLRScalar);
		bScalars.push_back(bLLScalar);
		bMin = MinV(bScalars);
		bMax = MaxV(bScalars);

		if (!(bMin <= aMax && bMax >= aMin))
		{
			return false;
		}
	}

	return true;
}