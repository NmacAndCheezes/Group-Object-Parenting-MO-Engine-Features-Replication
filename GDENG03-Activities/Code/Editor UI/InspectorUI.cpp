#include "InspectorUI.h"
#include "HeirarcyUI.h"
#include "HierarchyUI.h"
#include "../GameEngine/Components/Transform.h"
#include "../GameEngine/GameObjects/AGameObject.h"
#include "../GameEngine/Managers/GameObjectManager.h"

InspectorUI::InspectorUI(HeirarcyUI* HeirarcyUI) : heirarcyUI(HeirarcyUI)
{
}

InspectorUI::InspectorUI(HierarchyUI* hierarchyUI) : hierarchyUI(hierarchyUI)
{
}

void InspectorUI::update()
{
	/*if (heirarcyUI->selectedObject == nullptr) return;
	AGameObject* selected = heirarcyUI->selectedObject;*/

	if (hierarchyUI->selectedObject == nullptr) return;
	AGameObject* selected = hierarchyUI->selectedObject;
	Transform* t = selected->transform;

	pos[0] = t->LocalPosition.x;
	pos[1] = t->LocalPosition.y;
	pos[2] = t->LocalPosition.z;

	rot[0] = t->GetLocalEulerAngles().x;
	rot[1] = t->GetLocalEulerAngles().y;
	rot[2] = t->GetLocalEulerAngles().z;

	scale[0] = t->LocalScale.x;
	scale[1] = t->LocalScale.y;
	scale[2] = t->LocalScale.z;
	ImGui::Begin("Inspector");

	ImGui::Text(selected->Name.c_str());
	ImGui::InputFloat3("Position", pos);
	ImGui::InputFloat3("Rotation", rot);
	ImGui::InputFloat3("Scale", scale);

	for (auto i : GameObjectManager::GetInstance()->gameObjectList)
	{
		if (ImGui::Button(i->Name.c_str()))
		{
			selected->AttachChild(i);
		}
	}

	t->SetLocalPosition(Vector3(pos[0], pos[1], pos[2]));
	t->Rotate(Vector3(rot[0], rot[1], rot[2]));
	t->SetLocalScale(Vector3(scale[0], scale[1], scale[2]));
	ImGui::End();
}

InspectorUI::~InspectorUI()
{
}