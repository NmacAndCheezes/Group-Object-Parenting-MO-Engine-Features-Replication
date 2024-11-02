#pragma once
#include <list>
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

	std::list<AGameObject*> getGameObjectLists();
private:
	AGameObjectManager();
	static AGameObjectManager* sharedInstance;
	AGameObjectManager(AGameObjectManager const&) {}
	AGameObjectManager& operator=(AGameObjectManager const&) {};
	~AGameObjectManager();

private:
	std::list<AGameObject*> m_object_list;

private:
	friend class AGameObject;
};

