#pragma once
#include <list>
#include <map>
#include "AppWindow.h"
#include "Renderer.h"
#include "AGameObject.h"

class AGameObjectManager
{
public:
	void registerAGameObject(AGameObject* obj);
	void deleteAGameObject(AGameObject* obj);

	void update();

	static void initialize();
	static void destroy();
	static AGameObjectManager* get();
private:
	AGameObjectManager();
	static AGameObjectManager* sharedInstance;
	AGameObjectManager(AGameObjectManager const&) {}
	AGameObjectManager& operator=(AGameObjectManager const&) {};
	~AGameObjectManager();

	void reorderAGameObject(AGameObject* obj, int oldKey);
private:
	std::map<int, std::list<AGameObject*>> m_object_list;

private:
	friend class AGameObject;
	friend class Transform;
};

