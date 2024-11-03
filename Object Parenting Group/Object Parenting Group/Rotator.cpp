#include "Rotator.h"
#include "EngineTime.h"
#include "Transform.h"

Rotator::Rotator() : Component()
{
	rotationSpeed = Vector3D();
}

Rotator::Rotator(const Vector3D& vector) : Component()
{
	rotationSpeed = vector;
}

void Rotator::update()
{
	Vector3D new_rot = attachedObject->getTransform()->rotation() + (rotationSpeed * EngineTime::getDeltaTime());
	attachedObject->getTransform()->SetRotation(new_rot);
}

Rotator::~Rotator()
{
}