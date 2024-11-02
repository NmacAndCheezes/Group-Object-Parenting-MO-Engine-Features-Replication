#include "Transform.h"


Transform::Transform() 
	: Component(), m_position(Vector3D()), m_rotation(Vector3D()), m_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position) 
	: Component(), m_position(position), m_rotation(Vector3D()), m_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position, const Vector3D& rotation) 
	: Component(), m_position(position), m_rotation(rotation), m_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position, const Vector3D& rotation, const Vector3D& scale) 
	: Component(), m_position(position), m_rotation(rotation), m_scale(scale) { }

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

void Transform::SetRotation(const Vector3D& newPos)
{
	m_rotation = newPos;
}

void Transform::SetScale(const Vector3D& newPos)
{
	m_scale = newPos;
}

void Transform::SetPosition(float x, float y, float z)
{
	m_position.SetVector(x, y, z);
}

void Transform::SetRotation(float x, float y, float z)
{
	m_rotation.SetVector(x, y, z);
}

void Transform::SetScale(float x, float y, float z)
{
	m_scale.SetVector(x, y, z);
}


Vector3D Transform::position()
{
	return m_position;
}

Vector3D Transform::rotation()
{
	return m_rotation;
}

Vector3D Transform::scale()
{
	return m_scale;
}

Matrix4x4 Transform::getTransformMatrix()
{
	return m_transform_matrix;
}

AGameObject* Transform::attachedObject()
{
	return m_attached_obj;
}

Transform::~Transform()
{

}
