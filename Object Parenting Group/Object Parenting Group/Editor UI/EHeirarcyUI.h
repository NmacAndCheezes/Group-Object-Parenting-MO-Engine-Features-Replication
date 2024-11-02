#pragma once

#include "AUIScreen.h"

class AGameObject;
class EHeirarcyUI : public AUIScreen 
{
public:
	EHeirarcyUI();
	virtual void update() override;
	void printChild(AGameObject* obj, int layer);
	~EHeirarcyUI();

private:
	AGameObject* m_selected_gObj;
};