#pragma once
#include <DirectXMath.h>

class AGameObject;
class Transform
{
public:
	Transform(AGameObject* attachedObj);
	Transform(AGameObject* attachedObj, const DirectX::XMFLOAT3& initialPosition);
	Transform(AGameObject* attachedObj, const DirectX::XMFLOAT3& initialPosition, const DirectX::XMFLOAT3& initialRotation);
	Transform(AGameObject* attachedObj, const DirectX::XMFLOAT3& initialPosition, const DirectX::XMFLOAT3& initialRotation, const DirectX::XMFLOAT3& initialScale);
	~Transform();

	void update();

	void SetPosition(const DirectX::XMFLOAT3& vector);
	void SetLocalPosition(const DirectX::XMFLOAT3& vector);

	void SetRotation(const DirectX::XMFLOAT3& vector);
	void SetLocalRotation(const DirectX::XMFLOAT3& vector);

	void SetScale(const DirectX::XMFLOAT3& vector);
	void SetLocalScale(const DirectX::XMFLOAT3& vector);

	DirectX::XMFLOAT3 position();
	DirectX::XMFLOAT3 localPosition();

	DirectX::XMFLOAT3 rotation();
	DirectX::XMFLOAT3 localRotation();

	DirectX::XMFLOAT3 scale();
	DirectX::XMFLOAT3 localScale();

	DirectX::XMMATRIX getTransformMatrix();

	void RecalculateChildTransformWithoutParent();
	void RecalculateChildTransformWithParent(const Transform* parent);
private:
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_local_pos;
	
	DirectX::XMFLOAT3 m_rotation;
	DirectX::XMFLOAT3 m_local_rot;

	DirectX::XMFLOAT3 m_scale;
	DirectX::XMFLOAT3 m_local_scale;

	DirectX::XMMATRIX m_transform_matrix;

	AGameObject* m_attachedObj = nullptr;
};

