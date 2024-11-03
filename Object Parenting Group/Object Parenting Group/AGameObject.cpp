#include "AGameObject.h"
#include "Component.h"
#include "Transform.h"
#include "AGameObjectManager.h"

AGameObject::AGameObject() 
{ 
	AGameObjectManager::get()->registerAGameObject(this); 
	m_transform = new Transform();
}

AGameObject::AGameObject(std::string name) : m_name(name)
{
	AGameObjectManager::get()->registerAGameObject(this);
	m_transform = new Transform();
}

void AGameObject::update()
{
	if (!this->m_isActive) return;

	m_transform->update();

	for (auto c : m_component_list)
	{
		c->update();
	}

	
	//std::cout << "Position: " << position().X() << ", " << position().Y() << ", " << position().Z() << ", " << std::endl;
	//std::cout << "Rotation: " << rotation().X() << ", " << rotation().Y() << ", " << rotation().Z() << ", " << std::endl;
	//std::cout << "Scale: " << scale().X() << ", " << scale().Y() << ", " << scale().Z() << ", " << std::endl;
}

void AGameObject::attachComponent(Component* component)
{
	component->attachGameObject(this);
	m_component_list.push_back(component);
	std::cout << "Attached " << component->getName() << " to " << m_name;
}

void AGameObject::detachComponent(Component* component)
{
	component->detachGameObject();
	m_component_list.remove(component);
	std::cout << "Detached " << component->getName() << " from " << m_name;
}

void AGameObject::setId(int id)
{
	m_id = std::to_string(id) + m_name;
}

std::string AGameObject::getId()
{
	return m_id;
}

void AGameObject::setName(std::string name)
{
	m_name = name;
}

std::string AGameObject::getName()
{
	return m_name;
}

AGameObject::~AGameObject()
{
}

void AGameObject::setActive(bool isActive)
{
	this->m_isActive = isActive;
}

bool AGameObject::getActive()
{
	return m_isActive;
}

Transform* AGameObject::transform()
{
	return m_transform;
}
