#pragma once
#include "AUIScreen.h"

class HeirarcyUI;

class InspectorUI : public AUIScreen
{
public:
	InspectorUI(HeirarcyUI* HeirarcyUI);
	virtual void update() override;
	~InspectorUI();

private:
	HeirarcyUI* heirarcyUI;
	float pos[3];
	float rot[3];
	float scale[3];
};

