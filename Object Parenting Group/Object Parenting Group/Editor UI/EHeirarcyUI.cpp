#include "EHeirarcyUI.h"
#include "../AGameObjectManager.h"

EHeirarcyUI::EHeirarcyUI()
{
}

void EHeirarcyUI::update()
{
	if (!isActive) return;

	ImGui::Begin("Heirarcy");
	
	for (auto i : AGameObjectManager::get()->getGameObjectLists())
	{
		if (i->getParent() != nullptr) continue;

		if (ImGui::Button(i->getName().c_str()))
		{
			m_selected_gObj = i;
		}
		printChild(i, 0);
	}

	ImGui::End();
}

void EHeirarcyUI::printChild(AGameObject* obj, int layer)
{
	for (auto obj : obj->getChildren())
	{
		ImGui::Indent(10 + (10 * layer));
		if (ImGui::Button(obj->getName().c_str()))
		{
			m_selected_gObj = obj;
		}

		ImGui::Unindent(10 + (10 * layer));
		if (obj->getChildren().size() != 0) printChild(obj, layer + 1);

	}
}

EHeirarcyUI::~EHeirarcyUI()
{
}
