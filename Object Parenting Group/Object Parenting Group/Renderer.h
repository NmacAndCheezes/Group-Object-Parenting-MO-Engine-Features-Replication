#pragma once
#include "Component.h"
#include "AppWindow.h"
#include "Vector2D.h"

class Renderer : public Component
{
public:
	Renderer();
	virtual void update() {}
	//virtual void draw(AppWindow* target) = 0;
	~Renderer();
protected:
	struct vertex
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT2 texCoord;
	};


	__declspec(align(16))
		struct constant
	{
		DirectX::XMMATRIX m_world;
		DirectX::XMMATRIX m_view;
		DirectX::XMMATRIX m_proj;
		unsigned int m_time;
	};
};

