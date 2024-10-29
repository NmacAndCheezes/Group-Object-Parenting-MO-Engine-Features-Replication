#include "Component.h"
#include "AGameObject.h"

Component::Component() {}

void Component::attachGameObject(AGameObject* obj)
{
	attachedObject = obj;
}

void Component::detachGameObject()
{
	attachedObject = nullptr;
}

AGameObject* Component::getAttachedGameObject()
{
	return attachedObject;
}
