#pragma once
#include "Vector3D.h"
#include "Matrix4x4.h"
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
	void SetRotation(const Vector3D& vector);
	void SetScale(const Vector3D& vector);
	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	Vector3D position();
	Vector3D rotation();
	Vector3D scale();
	Matrix4x4 getTransformMatrix();
private:
	Vector3D m_position;
	Vector3D m_rotation;
	Vector3D m_scale;
	Matrix4x4 m_transform_matrix;

private:
	friend class AGameObject;
};

