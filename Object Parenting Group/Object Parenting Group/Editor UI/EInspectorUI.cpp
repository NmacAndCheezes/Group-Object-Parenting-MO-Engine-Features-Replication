#include "EInspectorUI.h"
#include "EHeirarcyUI.h"
#include "../Transform.h"
#include "../AGameObject.h"

EInspectorUI::EInspectorUI(EHeirarcyUI* heirarcy) : m_heirarcy(heirarcy)
{
}

void EInspectorUI::update()
{
	if (m_heirarcy->getSelectedObj() == nullptr)
	{
		return;
	}
		
	AGameObject* selected = m_heirarcy->getSelectedObj();
	Transform* t = selected->getTransform();

	pos[0] = t->localPosition().X();
	pos[1] = t->localPosition().Y();
	pos[2] = t->localPosition().Z();

	rot[0] = t->localRotation().X();
	rot[1] = t->localRotation().Y();
	rot[2] = t->localRotation().Z();

	scale[0] = t->localScale().X();
	scale[1] = t->localScale().Y();
	scale[2] = t->localScale().Z();
	ImGui::Begin("Inspector");

	ImGui::DragFloat3("Position", pos);
	ImGui::DragFloat3("Rotation", rot);
	ImGui::DragFloat3("Scale", scale);

	ImGui::End();
}

EInspectorUI::~EInspectorUI()
{
	delete m_heirarcy;
}
