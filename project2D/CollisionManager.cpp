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

bool CollisionManager::TestCollision(Entity* pObject)
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
			return true;
		}
	}

	return false;
}