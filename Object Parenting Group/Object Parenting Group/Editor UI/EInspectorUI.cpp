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

	pos[0] = t->localPosition().x;
	pos[1] = t->localPosition().y;
	pos[2] = t->localPosition().z;

	rot[0] = t->localRotation().x;
	rot[1] = t->localRotation().y;
	rot[2] = t->localRotation().z;

	scale[0] = t->localScale().x;
	scale[1] = t->localScale().y;
	scale[2] = t->localScale().z;

	bool isActive = selected->getActive();

	ImGui::Begin("Inspector");

	ImGui::Checkbox("active", &isActive);
	ImGui::SameLine();
	ImGui::Text(selected->getId().c_str());
	
	ImGui::DragFloat3("Position", pos);
	ImGui::DragFloat3("Rotation", rot);
	ImGui::DragFloat3("Scale", scale);

	ImGui::End();

	selected->setActive(isActive);
	selected->getTransform()->SetLocalPosition(DirectX::XMFLOAT3(pos[0], pos[1], pos[2]));
	selected->getTransform()->SetLocalRotation(DirectX::XMFLOAT3(rot[0], rot[1], rot[2]));
	selected->getTransform()->SetLocalScale(DirectX::XMFLOAT3(scale[0], scale[1], scale[2]));
}

EInspectorUI::~EInspectorUI()
{
	delete m_heirarcy;
}
