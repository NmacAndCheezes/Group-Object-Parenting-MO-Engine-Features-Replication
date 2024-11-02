#pragma once
#include <string>

class AGameObject;

class Component
{
public:
	Component();
	virtual void update() = 0;
	void attachGameObject(AGameObject* obj);
	void detachGameObject();
	AGameObject* getAttachedGameObject();
	~Component() {}
protected:
	AGameObject* attachedObject = nullptr;
};

