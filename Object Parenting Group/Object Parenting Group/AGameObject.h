#pragma once
#include <list>
#include "Matrix4x4.h"
#include "Vector3D.h"
#include "Window.h"
#include "Component.h"

#include <string>
#include <vector>

class Transform;

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

	Transform* transform();
	
protected:
	bool m_isActive = true;
	Transform* m_transform;
	std::list<Component*> m_component_list;
	std::string m_name;
	std::string m_id;

	AGameObject* m_parent;
	std::vector<AGameObject*> m_children;
private:
	friend class AGameObject;
};

