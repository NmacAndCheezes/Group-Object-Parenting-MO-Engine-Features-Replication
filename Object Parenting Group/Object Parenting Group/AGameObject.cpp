#include "AGameObject.h"
#include "Component.h"
#include "AGameObjectManager.h"

AGameObject::AGameObject() : m_transform(new Transform())
{
	AGameObjectManager::get()->registerAGameObject(this);	
}

AGameObject::AGameObject(std::string name) : m_name(name), m_transform(new Transform())
{
	AGameObjectManager::get()->registerAGameObject(this);
}

void AGameObject::update()
{
	if (!this->m_isActive) return;

	m_transform->update();

	for (auto c : m_component_list)
	{
		if (c) {
			c->update(); // Check if component is valid
		}
	}

	
	//std::cout << "Position: " << position().X() << ", " << position().Y() << ", " << position().Z() << ", " << std::endl;
	//std::cout << "Rotation: " << rotation().X() << ", " << rotation().Y() << ", " << rotation().Z() << ", " << std::endl;
	//std::cout << "Scale: " << scale().X() << ", " << scale().Y() << ", " << scale().Z() << ", " << std::endl;
}

void AGameObject::attachComponent(Component* component)
{
	component->attachGameObject(this);
	m_component_list.push_back(component);
	std::cout << "Attached " << component->getName() << " to " << m_name << std::endl;
}

void AGameObject::detachComponent(Component* component)
{
	component->detachGameObject();
	m_component_list.remove(component);
	std::cout << "Detached " << component->getName() << " from " << m_name << std::endl;
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
	delete m_transform;
}

void AGameObject::setActive(bool isActive)
{
	this->m_isActive = isActive;
}

bool AGameObject::getActive()
{
	return m_isActive;
}

Transform* AGameObject::getTransform()
{
	return m_transform;
}
