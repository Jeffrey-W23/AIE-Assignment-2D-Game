#include "CollisionManager.h"
#include <math.h>
#include "VectorCast.h"

CollisionManager* CollisionManager::m_Instance = nullptr;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::GetInstance()
{
	return m_Instance;
}

void CollisionManager::Create()
{
	if (!m_Instance)
	m_Instance = new CollisionManager();
}

void CollisionManager::Destory()
{
	delete m_Instance;
}

void CollisionManager::AddObject(Entity* pObject)
{
	m_CollisionList.push_back(pObject);
}

void CollisionManager::RemoveObject(Entity* pObject)
{
	auto iter = std::find(m_CollisionList.begin(), m_CollisionList.end(), pObject);

	if (iter != m_CollisionList.end())
	m_CollisionList.erase(iter);
}

// test 2 boxes
Entity* CollisionManager::TestBoxBoxCollision(Entity* pObject)
{
	for (int i = 0; i < m_CollisionList.size(); ++i)
	{
		if (pObject == m_CollisionList[i])
			continue;

		if (IsColliding(pObject, m_CollisionList[i]))
		{
			return m_CollisionList[i];
		}

		// Calculate AABB of our two objects
		//Collider collider1 = pObject->GetCollider();
		//collider1.m_TL += pObject->GetPosition();
		//collider1.m_BR += pObject->GetPosition();

		//Collider collider2 = m_CollisionList[i]->GetCollider();
		//collider2.m_TL += m_CollisionList[i]->GetPosition();
		//collider2.m_BR += m_CollisionList[i]->GetPosition();
	
		//// Test if two AABBs are overlapping
		//if (collider1.m_BR > collider2.m_TL && collider1.m_TL < collider2.m_BR)
		//{
		//	return m_CollisionList[i];
		//}
	}

	return nullptr;
}

 //test box and circle
Entity* CollisionManager::TestSphereBoxCollision(Entity* pObject)
{
	for (int i = 0; i < m_CollisionList.size(); ++i)
	{
		if (pObject == m_CollisionList[i])
			continue;

		// PUT IF HERE TO CHECK IF TYPE "THIS" // DIDNT WORK
		if (pObject->GetType() == m_CollisionList[i]->GetType())
			continue;
		
		// Calculate AABB
		Collider collider1 = m_CollisionList[i]->GetCollider();
		collider1.m_TL += m_CollisionList[i]->GetPosition();
		collider1.m_BR += m_CollisionList[i]->GetPosition();

		// Calculate AABB
		Collider collider2 = pObject->GetCollider();
		Vector2 pos = pObject->GetPosition();
		float rad = collider2.m_rad;

		// Calculate Circle
		Vector2 A = pos.Clamp(collider1.m_TL, collider1.m_BR);
		Vector2 V = A - pos;
		float VMag = V.magnitude();

		// Test if two AABBs are overlapping
		if (VMag <= rad * rad)
		{
			return m_CollisionList[i];
		}
	}

	return nullptr;
}

//collider of wall, dir of bullet
Vector2 CollisionManager::Bounce(Entity* pObject, Vector2 dir, Vector2 pos)
{
	Vector2 result;
	result = pos - pObject->GetPosition();

	if (fabsf(result.x) > fabsf(result.y))
		result.y = 0;
	else
		result.x = 0;
	
	Vector2 normal = Vector2::Normalised(result);
	return dir - 2 * dir.dot(normal) * normal;
}

// test 2 circles
//Entity* CollisionManager::TestSphereSphereCollision(Vector2 pos1, Vector2 pos2, float rad1, float rad2)
//{
//	for (int i = 0; i < m_CollisionList.size(); ++i)
//	{
//		Vector2 V = pos1 - pos2;
//		float VMag = V.magnitude();
//
//		// Test
//		if (VMag <= (rad1 * rad2) * (rad1 * rad2))
//		{
//			return m_CollisionList[i];
//		}
//	}
//
//	return nullptr;
//}






// SAT
Vector3 CollisionManager::Project(Vector3& a, Vector3& b)
{
	Vector3 result;

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

bool CollisionManager::IsColliding(Entity* a, Entity* b)
{
	rect rcA = a->boundingBox;
	rect rcB = b->boundingBox;

	Vector3 posa = CastTo<Vector3>(a->GetPosition());
	Vector3 posb = CastTo<Vector3>(b->GetPosition());

	Vector3 aUR = rcA.UpperRight + posa;
	Vector3 aUL = rcA.UpperLeft + posa;
	Vector3 aLR = rcA.LowerRight + posa;
	Vector3 aLL = rcA.LowerLeft + posa;

	Vector3 bUR = rcB.UpperRight + posb;
	Vector3 bUL = rcB.UpperLeft + posb;
	Vector3 bLR = rcB.LowerRight + posb;
	Vector3 bLL = rcB.LowerLeft + posb;

	float aMax = 0;
	float aMin = 0;
	float bMax = 0;
	float bMin = 0;

	Vector3 a1 = aUR - aUL;
	Vector3 a2 = aUR - aLR;
	Vector3 a3 = bUL - bLL;
	Vector3 a4 = bUL - bUR;

	vector<Vector3> axes;
	axes.push_back(a1);
	axes.push_back(a2);
	axes.push_back(a3);
	axes.push_back(a4);

	for (int i = 0; i < axes.size(); i++)
	{
		Vector3 aURProj = Project(aUR, axes[i]);
		Vector3 aULProj = Project(aUL, axes[i]);
		Vector3 aLRProj = Project(aLR, axes[i]);
		Vector3 aLLProj = Project(aLL, axes[i]);

		Vector3 bURProj = Project(bUR, axes[i]);
		Vector3 bULProj = Project(bUL, axes[i]);
		Vector3 bLRProj = Project(bLR, axes[i]);
		Vector3 bLLProj = Project(bLL, axes[i]);

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