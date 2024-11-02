#pragma once
#include "AGameObject.h"
#include <string>
class Component
{
public:
	Component();
	virtual void update() = 0;
	void attachGameObject(AGameObject* obj);
	void detachGameObject();
	AGameObject* getAttachedGameObject();
	~Component() {}

	std::string getName() { return typeid(this).name(); };
protected:
	AGameObject* attachedObject = nullptr;
};

