#include "EHeirarcyUI.h"
#include "../AGameObjectManager.h"

EHeirarcyUI::EHeirarcyUI()
{
}

void EHeirarcyUI::update()
{
	if (!isActive) return;

	ImGui::Begin("Color Picker");
	

	ImGui::End();
}

EHeirarcyUI::~EHeirarcyUI()
{
}
