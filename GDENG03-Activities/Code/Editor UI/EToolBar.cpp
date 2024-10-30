#include "EToolBar.h"
#include "EditorUIManager.h"
#include "../GameEngine/GameObjects/Primitives/CubeObject.h"
#include "../GameEngine/Managers/GameObjectManager.h"
EToolBar::EToolBar()
{
}

void EToolBar::update()
{
	ImGui::Begin("Toolbar");
    ImGui::SameLine(); // Keep buttons on the same line

    // Create a button
    if (ImGui::Button("Hover Me")) {
        CubeObject* cube = new CubeObject();
        GameObjectManager::GetInstance()->AddObject(cube);
        cube->GetTransform()->Position = { 0, 0, 0 };
    }

    ImGui::End();
}

EToolBar::~EToolBar()
{
}
