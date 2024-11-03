#include "../AGameObjectManager.h"
#include "EHeirarcyUI.h"
#include "../AGameObject.h"

EHeirarcyUI::EHeirarcyUI()
{

}

void EHeirarcyUI::update()
{
	if (!isActive) return;

	ImGui::Begin("Heirarcy");

	for (auto obj : AGameObjectManager::get()->getObjectList())
	{
		if (ImGui::Button(obj->getId().c_str()))
		{
			m_selected_gObj = obj;
			//std::cout << "Selected: " << m_selected_gObj->getId() << std::endl;
		}
	}

	ImGui::End();
}

AGameObject* EHeirarcyUI::getSelectedObj()
{
	return m_selected_gObj;
}

EHeirarcyUI::~EHeirarcyUI()
{
	delete m_selected_gObj;
}