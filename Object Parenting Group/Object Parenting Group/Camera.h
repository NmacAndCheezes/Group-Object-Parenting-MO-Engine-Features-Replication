#pragma once
//#include "Component.h" for implementing game camera
#include "AppWindow.h"
#include <DirectXMath.h>

enum ProjectionType { perspective = 0, orthographic = 1, isometric = 2 };
class Camera
{
public:
	Camera(AppWindow* window);
	DirectX::XMMATRIX getViewMatrix();
	DirectX::XMMATRIX getProjectionMatrix();
	void setViewType(int new_proj_type);

	DirectX::XMMATRIX getPositionMatrix();
	DirectX::XMMATRIX getRotationMatrix();
	virtual void updateCamera() = 0;
	~Camera();

	void SetPosition(const DirectX::XMFLOAT3& newPos);
	void SetRotation(const DirectX::XMFLOAT3& newRot);

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);

	DirectX::XMFLOAT3 position();
	DirectX::XMFLOAT3 rotation();

	bool getIsEnabled() { return isEnabled; }
protected:
	AppWindow* m_window;

	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_rotation;
	DirectX::XMMATRIX m_viewMatrix;
	DirectX::XMMATRIX m_projectionMatrix;

	ProjectionType ProjectionType = perspective;
	bool isEnabled = true;
};

