#include "HeirarcyUI.h"
#include "../GameEngine/Managers/GameObjectManager.h"
#include "../GameEngine/GameObjects/AGameObject.h"
HeirarcyUI::HeirarcyUI()
{
}

void HeirarcyUI::update()
{
	ImGui::Begin("Heirarcy");

	for (auto i : GameObjectManager::GetInstance()->gameObjectList)
	{
		if(ImGui::Button(i->Name.c_str()))
		{
			selectedObject = i;
		}
	}
	ImGui::End();
}

HeirarcyUI::~HeirarcyUI()
{
}
