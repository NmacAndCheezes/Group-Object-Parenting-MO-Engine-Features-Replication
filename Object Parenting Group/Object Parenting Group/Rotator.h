#pragma once
#include "Vector3D.h"
#include "Component.h"
class Rotator : public Component
{
public:
	Rotator();
	Rotator(const Vector3D& vector);
	virtual void update() override;
	~Rotator();
private:
	Vector3D rotationSpeed;
};

