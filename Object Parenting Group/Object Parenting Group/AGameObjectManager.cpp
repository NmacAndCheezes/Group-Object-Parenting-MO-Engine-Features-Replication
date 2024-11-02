#include "AGameObjectManager.h"
#include "AGameObject.h"

AGameObjectManager* AGameObjectManager::sharedInstance = nullptr;

AGameObjectManager::AGameObjectManager()
{

}

void AGameObjectManager::registerAGameObject(AGameObject* obj)
{
	obj->setId(m_object_list.size());
	m_object_list.push_back(obj);
}

void AGameObjectManager::deleteAGameObject(AGameObject* obj)
{
	m_object_list.remove(obj);
	delete obj;
}


void AGameObjectManager::update()
{
	for (auto obj : m_object_list)
	{
		if (!obj->getActive()) continue;
		obj->update();
	}
}

void AGameObjectManager::initialize()
{
	if (AGameObjectManager::sharedInstance) throw std::exception("AGameObjectManager already created");
	AGameObjectManager::sharedInstance = new AGameObjectManager();
}


void AGameObjectManager::destroy()
{
	if (!AGameObjectManager::sharedInstance) return;
	delete AGameObjectManager::sharedInstance;
}

AGameObjectManager* AGameObjectManager::get()
{
	static AGameObjectManager manager;
	return &manager;
}

std::list<AGameObject*> AGameObjectManager::getGameObjectLists()
{
	return m_object_list;
}

AGameObjectManager::~AGameObjectManager()
{

}
