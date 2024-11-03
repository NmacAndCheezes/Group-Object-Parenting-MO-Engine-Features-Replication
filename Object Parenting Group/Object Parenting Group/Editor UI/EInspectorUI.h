#pragma once
#include "AUIScreen.h"

class EHeirarcyUI;
class EInspectorUI : public AUIScreen
{
public:
	EInspectorUI(EHeirarcyUI* heirarcy);
	virtual void update() override;
	~EInspectorUI();

private:
	EHeirarcyUI* m_heirarcy;
	float pos[3];
	float rot[3];
	float scale[3];
};
