#include "CreditsScreen.h"


CreditsScreen::CreditsScreen()
{
	TexturePtr m_image = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"./Assets/Textures/wood.jpg");
	isActive = false;
}

void CreditsScreen::update()
{
	if (!isActive) return;
	
	ImGui::Begin("About");

	if (ImGui::Button("X", ImVec2(20, 20))) {
		isActive = false;
	}
	ImGui::GetBackgroundDrawList()->AddImage((ImTextureID)(intptr_t)m_image.get(), ImVec2(100, 100), ImVec2(100, 100));
	ImGui::Image((ImTextureID)(intptr_t)m_image.get(), ImVec2(100, 100));
	ImGui::Text("This engine was made by Nathan Macabanti\n");
	ImGui::Text("v 0.01\n");
	ImGui::Text("In partial requirement of WATCH - Video Lecture - Implementing Editor UI\n");

	ImGui::End();
}

CreditsScreen::~CreditsScreen()
{
}
