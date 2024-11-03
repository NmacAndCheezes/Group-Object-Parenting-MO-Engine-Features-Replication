#include <string>
#include "EditorCamera.h"
#include "InputSystem.h"
#include "EngineTime.h"

EditorCamera::EditorCamera(AppWindow* window) : Camera(window)
{
	initialPosition = m_position;
	initialRotation = m_rotation;
}

void EditorCamera::updateCamera()
{
	Camera::updateCamera();
}

void EditorCamera::move()
{
	if (!isEnabled) return;

	DirectX::XMMATRIX worldCam;
	DirectX::XMFLOAT3 new_pos;
	switch (ProjectionType)
	{
	case orthographic:
		new_pos = m_position + DirectX::XMFLOAT3(0, m_forward * 0.1f,0);
		new_pos = new_pos + DirectX::XMFLOAT3(0,0, m_right * 0.1f);
		break;
	default:
		new_pos = m_position + (DirectX::XMVectorGetZ(worldCam) * (m_forward * 0.1f));
		new_pos = new_pos + (worldCam.getXDirection() * (m_right * 0.1f));
		break;
	}
	
	
	worldCam = DirectX::XMMatrixTranslation(new_pos.x, new_pos.y, new_pos.z);
	

	m_position = DirectX::XMFLOAT3(worldCam.r[0].m128_f32);
	
	updateCamera();
}

void EditorCamera::onKeyDown(int key)
{
	float x = m_position.x;
	float y = m_position.y;
	float z = m_position.z;
	float moveSpeed = 10.0f;

	if (key == 'W')
	{
		//m_rot_x += 3.14f*m_delta_time;
		m_forward = 1.0f;
		move();
	}
	else if (key == 'S')
	{
		//m_rot_x -= 3.14f*m_delta_time;
		m_forward = -1.0f;
		move();
	}
	else if (key == 'A')
	{
		//m_rot_y += 3.14f*m_delta_time;
		m_right = -1.0f;
		move();
	}
	else if (key == 'D')
	{
		//m_rot_y -= 3.14f*m_delta_time;
		m_right = 1.0f;
		move();
	}
	else if (key == VK_SPACE)
	{
		this->SetPosition(initialPosition);
		this->SetRotation(initialPosition);
	}
	else if (key == 'Q') {
		if (InputSystem::get()->getLeftMouseDown())
		{
			y += EngineTime::getDeltaTime() * moveSpeed;
			this->SetPosition(x, y, z);
		}
		else
		{
			float x = m_rotation.x;
			float y = m_rotation.y;
			float z = m_rotation.z;

			z -= EngineTime::getDeltaTime() * moveSpeed;
			this->SetRotation(x, y, z);
		}
	}
	else if (key == 'E') {
		if (InputSystem::get()->getLeftMouseDown())
		{
			y -= EngineTime::getDeltaTime() * moveSpeed;
			this->SetPosition(x, y, z);
		}
		else
		{
			float x = m_rotation.x;
			float y = m_rotation.y;
			float z = m_rotation.z;

			z += EngineTime::getDeltaTime() * moveSpeed;
			this->SetRotation(x, y, z);
		}
	}
	else if (key == VK_SHIFT)
	{
		if (!is_HoldingP)
		{
			viewType++;
			if (viewType >= 3)
			{
				viewType = 0;
			}

			setViewType(viewType);

			is_HoldingP = true;
		}
		
	}

	//std::cout << "key pressed: " << char(key) << std::endl;
}


void EditorCamera::onKeyUp(int key)
{
	m_forward = 0.0f;
	m_right = 0.0f;

	if (key == VK_SHIFT && is_HoldingP)
	{
		is_HoldingP = false;
	}
}

void EditorCamera::onMouseMove(const Point& mouse_pos)
{
	if (InputSystem::get()->getLeftMouseDown() && ProjectionType != orthographic)
	{
		float x = m_rotation.x;
		float y = m_rotation.y;
		float z = m_rotation.z;

		float speed = 0.01;
		x += (mouse_pos.m_y - (m_window->Height() / 2.0f)) * EngineTime::getDeltaTime() * speed;
		y += (mouse_pos.m_x - (m_window->Width() / 2.0f)) * EngineTime::getDeltaTime() * speed;
		this->SetRotation(x, y, z);
	}
	
}

void EditorCamera::onLeftMouseDown(const Point& delta_mouse_pos)
{
	std::cout << "Left Mouse Down\n";
}

void EditorCamera::onLeftMouseUp(const Point& delta_mouse_pos)
{
	std::cout << "Left Mouse Up\n";
}

void EditorCamera::onRightMouseDown(const Point& delta_mouse_pos)
{
	std::cout << "Right Mouse Down\n";
}

void EditorCamera::onRightMouseUp(const Point& delta_mouse_pos)
{
	std::cout << "Right Mouse Up\n";
}


void EditorCamera::SetInitialPosition(const DirectX::XMFLOAT3& newPos)
{
	initialPosition = newPos;
	m_position = newPos;
	this->updateCamera();
}

void EditorCamera::SetInitialRotation(const DirectX::XMFLOAT3& newRot)
{
	initialRotation = newRot;
	m_rotation = newRot;
	this->updateCamera();
}

void EditorCamera::SetInitialPosition(float x, float y, float z)
{
	initialPosition = DirectX::XMFLOAT3(x, y, z);
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
	this->updateCamera();
}

void EditorCamera::SetInitialRotation(float x, float y, float z)
{
	initialRotation = DirectX::XMFLOAT3(x, y, z);
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
	this->updateCamera();
}

EditorCamera::~EditorCamera()
{
}
