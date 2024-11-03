#include "Transform.h"

Transform::Transform()
	: m_local_pos(Vector3D()), m_local_rot(Vector3D()), m_local_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position)
	: m_local_pos(position), m_local_rot(Vector3D()), m_local_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position, const Vector3D& rotation)
	: m_local_pos(position), m_local_rot(rotation), m_local_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position, const Vector3D& rotation, const Vector3D& scale)
	: m_local_pos(position), m_local_rot(rotation), m_local_scale(scale) { }

void Transform::update()
{
	m_transform_matrix.setIdentity();
	Matrix4x4 allMatrix; allMatrix.setIdentity();
	Matrix4x4 translationMatrix; translationMatrix.setTranslation(this->position());
	Matrix4x4 scaleMatrix; scaleMatrix.setScale(this->scale());

	Vector3D rotation = this->rotation();
	Matrix4x4 zMatrix; zMatrix.setRotationZ(rotation.Z());
	//zMatrix.printMatrix();
	Matrix4x4 xMatrix; xMatrix.setRotationX(rotation.X());
	//xMatrix.printMatrix();
	Matrix4x4 yMatrix; yMatrix.setRotationY(rotation.Y());
	//yMatrix.printMatrix();

	//Scale --> Rotate --> Transform as recommended order.
	Matrix4x4 rotMatrix; rotMatrix.setIdentity();
	rotMatrix = rotMatrix.multiplyTo(xMatrix.multiplyTo(yMatrix.multiplyTo(zMatrix)));
	allMatrix = allMatrix.multiplyTo(scaleMatrix.multiplyTo(rotMatrix));
	allMatrix = allMatrix.multiplyTo(translationMatrix);

	m_transform_matrix = allMatrix;
}

void Transform::SetPosition(const Vector3D& newPos)
{
	m_position = newPos;
}

void Transform::SetLocalPosition(const Vector3D& vector)
{
	m_local_pos = vector;
}

void Transform::SetRotation(const Vector3D& newPos)
{
	m_rotation = newPos;
}

void Transform::SetLocalRotation(const Vector3D& vector)
{
	m_local_rot = vector;
}

void Transform::SetScale(const Vector3D& newPos)
{
	m_scale = newPos;
}

void Transform::SetLocalScale(const Vector3D& vector)
{
	m_local_scale = vector;
}


Vector3D Transform::position()
{
	return m_position;
}

Vector3D Transform::localPosition()
{
	return Vector3D();
}

Vector3D Transform::rotation()
{
	return m_rotation;
}

Vector3D Transform::localRotation()
{
	return Vector3D();
}

Vector3D Transform::scale()
{
	return m_scale;
}

Vector3D Transform::localScale()
{
	return Vector3D();
}

Matrix4x4 Transform::getTransformMatrix()
{
	return m_transform_matrix;
}

Transform::~Transform()
{

}
