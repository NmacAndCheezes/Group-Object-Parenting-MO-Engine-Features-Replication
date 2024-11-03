#pragma once
#include <list>
#include "Matrix4x4.h"
#include "Vector3D.h"
#include "Window.h"
#include "Transform.h"
#include <string>
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

	void setName(std::string);
	std::string getName();
	~AGameObject();

	void setActive(bool isActive);
	bool getActive();

	Transform* getTransform();
	
protected:
	bool m_isActive = true;
	Transform* m_transform = new Transform();
	std::list<Component*> m_component_list;
	std::string m_name;
	std::string m_id;

private:
	friend class Transform;
};

