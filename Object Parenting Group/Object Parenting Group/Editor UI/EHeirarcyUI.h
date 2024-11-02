#pragma once
#include "AUIScreen.h"

class AGameObject;
class EHeirarcyUI : public AUIScreen
{
public:
	EHeirarcyUI();
	virtual void update() override;
	~EHeirarcyUI();

private:
	AGameObject* m_selected_gObj;
};
