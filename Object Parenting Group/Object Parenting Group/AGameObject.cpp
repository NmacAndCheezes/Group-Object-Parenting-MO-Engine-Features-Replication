#include "AGameObject.h"
#include "Component.h"
#include "AGameObjectManager.h"
#include "Transform.h"
#include "Component.h"

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
		c->update();
	}


	//std::cout << "Position: " << position().X() << ", " << position().Y() << ", " << position().Z() << ", " << std::endl;
	//std::cout << "Rotation: " << rotation().X() << ", " << rotation().Y() << ", " << rotation().Z() << ", " << std::endl;
	//std::cout << "Scale: " << scale().X() << ", " << scale().Y() << ", " << scale().Z() << ", " << std::endl;
}

void AGameObject::attachComponent(Component* component)
{
	if (component == nullptr) return;
	component->attachGameObject(this);
	m_component_list.push_back(component);
	//std::cout << "Attached " << component->getName() << " to " << m_name;
}

void AGameObject::detachComponent(Component* component)
{
	if (component == nullptr) return;
	component->detachGameObject();
	m_component_list.remove(component);
	//std::cout << "Detached " << component->getName() << " from " << m_name;
}

void AGameObject::setId(int id)
{
	m_id = std::to_string(id) + m_name;
}

std::string AGameObject::getId()
{
	return m_id;
}

std::string AGameObject::getName()
{
	return m_name;
}

AGameObject::~AGameObject()
{
	m_children.clear();
	m_component_list.clear();
	delete m_parent;
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

void AGameObject::attachChild(AGameObject* child)
{
	if (child == nullptr || child == this)
	{
		//Nothing was attached
		return;
	}

	if (child->m_parent != nullptr)
	{
		child->m_parent->detachChild(child);
	}

	this->m_children.push_back(child);
	child->setParent(this);
}

void AGameObject::detachChild(AGameObject* child)
{
	if (child == this || child == nullptr) return;

	this->m_children.remove(child);

	child->setParent(NULL);
}

std::list<AGameObject*> AGameObject::getChildren()
{
	return m_children;
}

void AGameObject::setParent(AGameObject* parent)
{
	this->m_parent = parent;
}

AGameObject* AGameObject::getParent()
{
	return this->m_parent;
}

Transform* AGameObject::transform()
{
	return this->m_transform;
}
