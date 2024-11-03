#include "Transform.h"
#include "AGameObject.h"
#include "Math.h"

Transform::Transform(AGameObject* attachedObj)
	: m_attachedObj(attachedObj), m_local_pos(Vector3D()), m_local_rot(Vector3D()), m_local_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(AGameObject* attachedObj, const Vector3D& position)
	: m_attachedObj(attachedObj), m_local_pos(position), m_local_rot(Vector3D()), m_local_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(AGameObject* attachedObj, const Vector3D& position, const Vector3D& rotation)
	: m_attachedObj(attachedObj), m_local_pos(position), m_local_rot(rotation), m_local_scale(Vector3D(1, 1, 1)) { }

Transform::Transform(AGameObject* attachedObj, const Vector3D& position, const Vector3D& rotation, const Vector3D& scale)
	: m_attachedObj(attachedObj), m_local_pos(position), m_local_rot(rotation), m_local_scale(scale) { }

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

	//std::cout << "Position: " << position().X() << ", " << position().Y() << ", " << position().Z() << ", " << std::endl;
	//std::cout << "Rotation: " << rotation().X() << ", " << rotation().Y() << ", " << rotation().Z() << ", " << std::endl;
	//std::cout << "Scale: " << scale().X() << ", " << scale().Y() << ", " << scale().Z() << ", " << std::endl;
}

void Transform::SetPosition(const Vector3D& newPos)
{
	m_local_pos = Vector3D(
		newPos.X() - position().X(),
		newPos.Y() - position().Y(),
		newPos.Z() - position().Z()
	);
	update();
}

void Transform::SetLocalPosition(const Vector3D& vector)
{
	m_local_pos = vector;
	update();
}

void Transform::SetRotation(const Vector3D& newRot)
{
	m_local_rot = Vector3D(
		Math::toRadians(newRot.X() - rotation().X()),
		Math::toRadians(newRot.Y() - rotation().Y()),
		Math::toRadians(newRot.Z() - rotation().Z())
	);
	update();
}

void Transform::SetLocalRotation(const Vector3D& vector)
{
	m_local_rot = Vector3D(
		Math::toRadians(vector.X()),
		Math::toRadians(vector.Y()),
		Math::toRadians(vector.Z())
	);
	update();
}

void Transform::SetScale(const Vector3D& newScale)
{
	m_local_scale = Vector3D(
		newScale.X() - scale().X(),
		newScale.Y() - scale().Y(),
		newScale.Z() - scale().Z()
	);
	update();
}

void Transform::SetLocalScale(const Vector3D& vector)
{
	m_local_scale = vector;
	update();
}


Vector3D Transform::position()
{
	Vector3D pos = m_attachedObj->getParent() != nullptr ? 
		m_attachedObj->getParent()->getTransform()->localPosition() + m_local_pos 
		: m_local_pos;
	return pos;
}

Vector3D Transform::localPosition()
{
	return m_local_pos;
}

Vector3D Transform::rotation()
{
	Vector3D rot = m_attachedObj->getParent() != nullptr 
		? m_attachedObj->getParent()->getTransform()->localRotation() + m_local_rot 
		: m_local_rot;
	return rot;
}

Vector3D Transform::localRotation()
{
	return m_local_rot;
}

Vector3D Transform::scale()
{
	Vector3D scale = m_attachedObj->getParent() != nullptr ? 
		m_attachedObj->getParent()->getTransform()->localScale() + m_local_scale
		: m_local_scale;
	return scale;
}

Vector3D Transform::localScale()
{
	return m_local_scale;
}

Matrix4x4 Transform::getTransformMatrix()
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
