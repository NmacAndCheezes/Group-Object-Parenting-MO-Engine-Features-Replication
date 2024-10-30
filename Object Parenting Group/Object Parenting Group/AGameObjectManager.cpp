#include "AGameObjectManager.h"
#include "AGameObject.h"

AGameObjectManager* AGameObjectManager::sharedInstance = nullptr;

AGameObjectManager::AGameObjectManager()
{

}

void AGameObjectManager::registerAGameObject(AGameObject* obj)
{
	//obj->setId(m_object_list.size());
	m_object_list[obj->transform()->childIndex].push_back(obj);
}

void AGameObjectManager::reorderAGameObject(AGameObject* obj, int oldKey)
{
	m_object_list[oldKey].remove(obj);
	m_object_list[obj->transform()->childIndex].push_back(obj);
}

void AGameObjectManager::deleteAGameObject(AGameObject* obj)
{
	m_object_list[obj->transform()->childIndex].remove(obj);
	delete obj;
}


void AGameObjectManager::update()
{
	for (auto i = m_object_list.begin(); i != m_object_list.end(); i++) {
		for (auto obj : i->second)
		{
			if (!obj->getActive()) continue;
			obj->update();
		}
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

AGameObjectManager::~AGameObjectManager()
{

}
