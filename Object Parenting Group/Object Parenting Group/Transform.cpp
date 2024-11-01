#include "Transform.h"
#include "AGameObjectManager.cpp"

Transform::Transform()
	: m_position(Vector3D()), m_rotation(Vector3D()), m_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position) 
	: m_position(position), m_rotation(Vector3D()), m_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position, const Vector3D& rotation) 
	: m_position(position), m_rotation(rotation), m_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(const Vector3D& position, const Vector3D& rotation, const Vector3D& scale) 
	: m_position(position), m_rotation(rotation), m_scale(scale) { }

void Transform::update()
{
	m_transform_matrix.setIdentity();
	Matrix4x4 allMatrix; allMatrix.setIdentity();

	if (m_parent != nullptr)
	{
		m_position = m_parent->position() + m_localPosition;
		m_rotation = m_parent->position() + m_localPosition;
	}
		
	Matrix4x4 translationMatrix; translationMatrix.setTranslation(this->m_position);
	Matrix4x4 scaleMatrix; scaleMatrix.setScale(this->m_scale);

	Matrix4x4 zMatrix; zMatrix.setRotationZ(this->m_rotation.Z());
	//zMatrix.printMatrix();
	Matrix4x4 xMatrix; xMatrix.setRotationX(this->m_rotation.X());
	//xMatrix.printMatrix();
	Matrix4x4 yMatrix; yMatrix.setRotationY(this->m_rotation.Y());
	//yMatrix.printMatrix();

	//Scale --> Rotate --> Transform as recommended order.
	Matrix4x4 rotMatrix; rotMatrix.setIdentity();
	rotMatrix = rotMatrix.multiplyTo(xMatrix.multiplyTo(yMatrix.multiplyTo(zMatrix)));
	allMatrix = allMatrix.multiplyTo(scaleMatrix.multiplyTo(rotMatrix));
	allMatrix = allMatrix.multiplyTo(translationMatrix);

	m_transform_matrix = allMatrix;
}

void Transform::setGameObject(AGameObject* obj)
{
	attachedGameObject = obj;
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

void Transform::SetLocalPosition(const Vector3D& vector)
{
	m_localPosition = vector;
}

void Transform::SetLocalRotation(const Vector3D& vector)
{
	m_localRotation = vector;
}

void Transform::SetLocalScale(const Vector3D& vector)
{
	m_localScale = vector;
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


void Transform::SetParent(Transform* parent)
{
	int oldChildIndex = childIndex;
	if (parent == nullptr) 
	{ 
		childIndex = 0;
	}
	else
	{
		m_parent = parent;
		childIndex = m_parent->childIndex + 1;
		m_localPosition = m_parent->m_position - m_position;
		m_localRotation = m_parent->m_rotation - m_rotation;
		m_localScale = m_parent->m_scale - m_scale;
	}
	AGameObjectManager::get()->reorderAGameObject(attachedGameObject, oldChildIndex);
}

int Transform::getChildIndex()
{
	return childIndex;
}

Vector3D Transform::position()
{
	return m_position;
}

Vector3D Transform::localPosition()
{
	return m_parent->m_position - m_position;
}

Vector3D Transform::rotation()
{
	return m_rotation;
}

Vector3D Transform::localRotation()
{
	return m_parent->m_rotation - m_position;
}

Vector3D Transform::scale()
{
	return m_scale;
}

Vector3D Transform::localScale()
{
	return m_parent->m_scale - m_scale;
}

Matrix4x4 Transform::getTransformMatrix()
{
	return m_transform_matrix;
}

Transform::~Transform()
{

}
