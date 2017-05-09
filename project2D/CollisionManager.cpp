#include "CollisionManager.h"

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

		// Calculate AABB of our two objects
		Collider collider1 = pObject->GetCollider();
		collider1.m_TL += pObject->GetPosition();
		collider1.m_BR += pObject->GetPosition();

		Collider collider2 = m_CollisionList[i]->GetCollider();
		collider2.m_TL += m_CollisionList[i]->GetPosition();
		collider2.m_BR += m_CollisionList[i]->GetPosition();
	
		// Test if two AABBs are overlapping
		if (collider1.m_BR > collider2.m_TL && collider1.m_TL < collider2.m_BR)
		{
			return m_CollisionList[i];
		}
	}

	return nullptr;
}

 //test box and circle
Entity* CollisionManager::TestSphereBoxCollision(Entity* pObject)
{
	for (int i = 0; i < m_CollisionList.size(); ++i)
	{
		// PUT IF HERE TO CHECK IF TYPE "THIS"


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

// test 2 circles
Entity* CollisionManager::TestSphereSphereCollision(Vector2 pos1, Vector2 pos2, float rad1, float rad2)
{
	for (int i = 0; i < m_CollisionList.size(); ++i)
	{
		Vector2 V = pos1 - pos2;
		float VMag = V.magnitude();

		// Test
		if (VMag <= (rad1 * rad2) * (rad1 * rad2))
		{
			return m_CollisionList[i];
		}
	}

	return nullptr;
}