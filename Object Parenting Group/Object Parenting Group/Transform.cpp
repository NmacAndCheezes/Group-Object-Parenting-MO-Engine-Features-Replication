#include "Transform.h"
#include "AGameObject.h"
#include "Math.h"

Transform::Transform(AGameObject* attachedObj)
	: m_attachedObj(attachedObj), 
	m_local_pos(DirectX::XMFLOAT3(0,0,0)),
	m_local_rot(DirectX::XMFLOAT3(0, 0, 0)),
	m_local_scale(DirectX::XMFLOAT3(1, 1, 1)) { }

Transform::Transform(AGameObject* attachedObj, const DirectX::XMFLOAT3& position)
	: m_attachedObj(attachedObj), 
	m_local_pos(position), 
	m_local_rot(DirectX::XMFLOAT3(0, 0, 0)), 
	m_local_scale(DirectX::XMFLOAT3(1, 1, 1)) { }

Transform::Transform(AGameObject* attachedObj, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation)
	: m_attachedObj(attachedObj), m_local_pos(position), m_local_rot(rotation), m_local_scale(DirectX::XMFLOAT3(1, 1, 1)) { }

Transform::Transform(AGameObject* attachedObj, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation, const DirectX::XMFLOAT3& scale)
	: m_attachedObj(attachedObj), m_local_pos(position), m_local_rot(rotation), m_local_scale(scale) { }

void Transform::update()
{
	// Create translation, rotation, and scale matrices
	DirectX::XMMATRIX translation = DirectX::XMMatrixTranslation(m_position.x, m_position.y, m_position.z);
	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(m_rotation.x, m_rotation.y, m_rotation.z);
	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(m_scale.x, m_scale.y, m_scale.z);

	// Combine transformations
	m_transform_matrix = scale * rotation * translation; // Order of transformations is important

	//std::cout << "Position: " << position().X() << ", " << position().Y() << ", " << position().Z() << ", " << std::endl;
	//std::cout << "Rotation: " << rotation().X() << ", " << rotation().Y() << ", " << rotation().Z() << ", " << std::endl;
	//std::cout << "Scale: " << scale().X() << ", " << scale().Y() << ", " << scale().Z() << ", " << std::endl;
}

void Transform::SetPosition(const DirectX::XMFLOAT3& newPos)
{
	m_position = newPos;
	update();
}

void Transform::SetLocalPosition(const DirectX::XMFLOAT3& newPos)
{
	m_local_pos = newPos;
	update();
}

void Transform::SetRotation(const DirectX::XMFLOAT3& newRot)
{
	m_rotation = newRot;
	update();
}

void Transform::SetLocalRotation(const DirectX::XMFLOAT3& newRot)
{
	m_local_rot = newRot;
	update();
}

void Transform::SetScale(const DirectX::XMFLOAT3& newScale)
{
	m_scale = newScale;
	update();
}

void Transform::SetLocalScale(const DirectX::XMFLOAT3& vector)
{
	m_local_scale = vector;
	update();
}


DirectX::XMFLOAT3 Transform::position()
{
	return m_position;
}

DirectX::XMFLOAT3 Transform::localPosition()
{
	return m_local_pos;
}

DirectX::XMFLOAT3 Transform::rotation()
{
	return m_rotation;
}

DirectX::XMFLOAT3 Transform::localRotation()
{
	return m_local_rot;
}

DirectX::XMFLOAT3 Transform::scale()
{
	return m_scale;
}

DirectX::XMFLOAT3 Transform::localScale()
{
	return m_local_scale;
}

DirectX::XMMATRIX Transform::getTransformMatrix()
{
	return m_transform_matrix;
}

void Transform::RecalculateChildTransformWithoutParent()
{
	m_local_pos = position();
	m_local_scale = scale();
	m_local_rot = rotation();

	// no need to update children since the local and global values are still the same 
}

Transform::~Transform()
{

}
