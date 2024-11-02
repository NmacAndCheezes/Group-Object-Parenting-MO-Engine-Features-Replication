#include "EToolBar.h"
#include "EditorUIManager.h"
EToolBar::EToolBar()
{
}

void EToolBar::update()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always); // Set position to top-left
	ImGui::Begin("Toolbar", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::SameLine(); // Keep buttons on the same line

    if (ImGui::Button("About")) {
        EditorUIManager::get()->getUIScreen("Credits")->setIsActive(true);
    }
    ImGui::SameLine();
    if (ImGui::Button("Color Picker")) {
        EditorUIManager::get()->getUIScreen("Color Picker")->setIsActive(true);
    }
    ImGui::End();
}

EToolBar::~EToolBar()
{
}
