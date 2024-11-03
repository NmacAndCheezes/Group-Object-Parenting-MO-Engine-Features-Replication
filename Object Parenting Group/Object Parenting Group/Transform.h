#pragma once
#include "Vector3D.h"
#include "Matrix4x4.h"

class AGameObject;
class Transform
{
public:
	Transform();
	Transform(const Vector3D& initialPosition);
	Transform(const Vector3D& initialPosition, const Vector3D& initialRotation);
	Transform(const Vector3D& initialPosition, const Vector3D& initialRotation, const Vector3D& initialScale);
	~Transform();

	void update();

	void SetPosition(const Vector3D& vector);
	void SetLocalPosition(const Vector3D& vector);

	void SetRotation(const Vector3D& vector);
	void SetLocalRotation(const Vector3D& vector);

	void SetScale(const Vector3D& vector);
	void SetLocalScale(const Vector3D& vector);

	Vector3D position();
	Vector3D localPosition();

	Vector3D rotation();
	Vector3D localRotation();

	Vector3D scale();
	Vector3D localScale();

	Matrix4x4 getTransformMatrix();
private:
	Vector3D m_position;
	Vector3D m_local_pos;

	Vector3D m_rotation;
	Vector3D m_local_rot;

	Vector3D m_scale;
	Vector3D m_local_scale;

	Matrix4x4 m_transform_matrix;
};

