#pragma once
#include "Component.h"

class WarpCubeToPlane : public Component
{
public:
	WarpCubeToPlane() {}
	virtual void update() override;
	~WarpCubeToPlane() {}

private:
	float m_delta_scale = 0.0f;
};