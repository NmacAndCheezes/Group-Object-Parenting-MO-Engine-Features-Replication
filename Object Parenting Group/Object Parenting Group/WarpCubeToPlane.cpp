#include "WarpCubeToPlane.h"
#include "EngineTime.h"
#include "Math.h"

void WarpCubeToPlane::update()
{
	m_delta_scale += EngineTime::getDeltaTime();
	if (m_delta_scale >= 2 * Math::pi()) m_delta_scale = 0;

	Vector3D new_scale = Vector3D::lerp(Vector3D::ones(), Vector3D(2,0,2), (sin(m_delta_scale) + 1) / 2.f);
	attachedObject->transform()->SetScale(new_scale);
}