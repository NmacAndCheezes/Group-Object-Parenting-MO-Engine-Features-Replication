#pragma once
#include "Matrix4x4.h"
#include "Vector3D.h"
#include "Window.h"
#include "Component.h"
#include "Transform.h"

#include <string>
#include <list>

class Component;
class AGameObject
{
public:
	AGameObject();
	AGameObject(std::string name);
	virtual void update();

	virtual void attachComponent(Component* component);
	virtual void detachComponent(Component* component);
	
	void setId(int id);
	std::string getId();
	std::string getName();
	~AGameObject();

	void setActive(bool isActive);
	bool getActive();

	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	std::list<AGameObject*> getChildren();

	void setParent(AGameObject* parent);
	AGameObject* getParent();

	Transform* transform();
	
protected:
	bool m_isActive = true;
	Transform* m_transform = nullptr;
	std::list<Component*> m_component_list;
	std::string m_name;
	std::string m_id;

	AGameObject* m_parent;
	std::list<AGameObject*> m_children;
};

