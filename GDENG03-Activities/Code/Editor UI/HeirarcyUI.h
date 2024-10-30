#pragma once
#include "AUIScreen.h"
class AGameObject;

class HeirarcyUI : public AUIScreen
{
public:
	HeirarcyUI();
	virtual void update() override;
	~HeirarcyUI();
private:
	AGameObject* selectedObject = nullptr;
private:
	friend class InspectorUI;
};

