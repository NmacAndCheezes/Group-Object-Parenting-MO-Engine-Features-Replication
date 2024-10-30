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

	void setGameObject(AGameObject* obj);

	void SetPosition(const Vector3D& vector);
	void SetRotation(const Vector3D& vector);
	void SetScale(const Vector3D& vector);

	void SetLocalPosition(const Vector3D& vector);
	void SetLocalRotation(const Vector3D& vector);
	void SetLocalScale(const Vector3D& vector);

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	void SetParent(Transform* parent);
	int getChildIndex();
	Vector3D position();
	Vector3D localPosition();
	
	Vector3D rotation();
	Vector3D localRotation();

	Vector3D scale();
	Vector3D localScale();
	Matrix4x4 getTransformMatrix();
private:
	Vector3D m_position;
	Vector3D m_localPosition;

	Vector3D m_rotation;
	Vector3D m_localRotation;

	Vector3D m_scale;
	Vector3D m_localScale;

	Transform* m_parent;
	Matrix4x4 m_transform_matrix;

	int childIndex;

	AGameObject* attachedGameObject;
private:
	friend class AGameObject;
	friend class AGameObjectManager;
};

