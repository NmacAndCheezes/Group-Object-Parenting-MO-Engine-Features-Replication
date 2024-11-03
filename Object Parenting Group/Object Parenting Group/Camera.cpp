#include "Camera.h"
#include <DirectXMath.h>

Camera::Camera(AppWindow* window) : m_window(window)
{
}

DirectX::XMMATRIX Camera::getViewMatrix()
{
	return m_viewMatrix;
}

DirectX::XMMATRIX Camera::getProjectionMatrix()
{
	return m_projectionMatrix;
}

void Camera::setViewType(int new_proj_type)
{
	if (new_proj_type >= 3)
	{
		new_proj_type %= 3;
	}

	std::string s_proj;

	switch (new_proj_type)
	{
	case 0:
		ProjectionType = perspective;
		s_proj = "perspective";
		break;
	case 1:
		ProjectionType = orthographic;
		s_proj = "orthographic";
		break;
	case 2:
		ProjectionType = isometric;
		s_proj = "isometric";
		break;
	}

	std::cout << "Projection type: " << s_proj << std::endl;
	updateCamera();
}

DirectX::XMMATRIX Camera::getPositionMatrix()
{
	return DirectX::XMMatrixTranslation(m_position.x, m_position.y, m_position.z);
}

DirectX::XMMATRIX Camera::getRotationMatrix()
{
#if 1
	switch (ProjectionType)
	{
	case orthographic:
		return DirectX::XMMatrixRotationRollPitchYaw(0, 0, m_rotation.z);
	default:
		return DirectX::XMMatrixRotationRollPitchYaw(m_rotation.x, m_rotation.y, m_rotation.z);
	}
#endif
}

void Camera::updateCamera()
{
	if (!isEnabled) return;

	DirectX::XMMATRIX translation = getPositionMatrix();
	DirectX::XMMATRIX rotation = getRotationMatrix();
	
	m_viewMatrix = rotation * translation;

	if (ProjectionType == perspective)
	{
		DirectX::XMVECTOR Eye = DirectX::XMVectorSet(m_position.x, m_position.y, -1.0f, 0.0f);
		DirectX::XMVECTOR LookAt = DirectX::XMVectorSet(m_position.x, m_position.y, 0.0f, 0.0f);
		DirectX::XMVECTOR Up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		DirectX::XMMatrixLookAtLH(Eye, LookAt, Up);
	}
#pragma region Setting Projection Based on projection type;
	switch (ProjectionType)
	{
		case perspective:
			m_projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(1, this->m_window->AspectRatio(), 0.1f, 1000.0f);
			break;
		default:
			m_projectionMatrix = DirectX::XMMatrixOrthographicLH
			(
				(m_window->Width()) / 300.0f,
				(m_window->Height()) / 300.0f,
				-100.0f,
				100.0f
			);
			break;
	}
#pragma endregion
	//this->m_viewMatrix.printMatrix();
}

Camera::~Camera()
{
}

void Camera::SetPosition(const DirectX::XMFLOAT3& newPos)
{
	m_position = newPos;
	this->updateCamera();
}

void Camera::SetRotation(const DirectX::XMFLOAT3& newRot)
{
	m_rotation = newRot;
	this->updateCamera();
}

void Camera::SetPosition(float x, float y, float z)
{
	m_position = DirectX::XMFLOAT3(x, y, z);
	this->updateCamera();
}

void Camera::SetRotation(float x, float y, float z)
{
	m_rotation = DirectX::XMFLOAT3(x, y, z);
	this->updateCamera();
}


DirectX::XMFLOAT3 Camera::position()
{
	return m_position;
}

DirectX::XMFLOAT3 Camera::rotation()
{
	return m_rotation;
}
