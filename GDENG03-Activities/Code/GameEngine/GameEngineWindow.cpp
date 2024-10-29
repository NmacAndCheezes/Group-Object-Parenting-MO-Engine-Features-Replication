#include "GameEngineWindow.h"
#include "EngineTime.h"
#include "Managers/GameObjectManager.h"
#include "GameObjects/FreeCameraObject.h"

#include "GameObjects/Primitives/CubeObject.h"
#include "GameObjects/Primitives/ConeObject.h"
#include "GameObjects/Primitives/CylinderObject.h"
#include "GameObjects/Primitives/SphereObject.h"



GameEngineWindow::GameEngineWindow(int fps) : fps(fps), currDelta(0.f)
{
	windowClassName = "GameEngineClass";
}

GameEngineWindow::~GameEngineWindow()
{ 

}

void GameEngineWindow::OnCreate(HWND hWnd)
{
	// initialize game engine
	GraphicsEngine::GetInstance()->Init();
	GraphicsEngine::GetInstance()->SetViewport(windowSize.right - windowSize.left, windowSize.bottom - windowSize.top);
	swapChain = GraphicsEngine::GetInstance()->CreateSwapChain(hWnd, windowSize.right - windowSize.left, windowSize.bottom - windowSize.top);
	EngineTime::Initialize();


	// setup the objects
	FreeCameraObject* freeCam = new FreeCameraObject(width, height); 
	freeCam->GetTransform()->Position = { 0.0f, 0.0f, 0.0f }; 
	GameObjectManager::GetInstance()->AddObject(freeCam); 
}

void GameEngineWindow::OnUpdate()
{
	swapChain->ClearBuffer(0.4f, 0.4f, 0.6f);

	currDelta += (float)EngineTime::GetDeltaTime();
	float secsPerFrame = 1.f / (float)fps;
	if (currDelta >= secsPerFrame) 
	{
		currDelta -= secsPerFrame; 
		GameObjectManager::GetInstance()->Update(secsPerFrame); 

		Keyboard::FlushEventsBuffer();  
		Keyboard::FlushCharBuffer(); 
		Mouse::FlushEventsBuffer(); 
	}

	GameObjectManager::GetInstance()->Draw(); 
	swapChain->Present(true); 
}

void GameEngineWindow::OnDestroy() 
{ 
	Window::OnDestroy();

	GraphicsEngine::GetInstance()->Release();
	// engine time???
	// other more managers???
}

LRESULT GameEngineWindow::HandleWindowMessages(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	return Window::HandleWindowMessages(hWnd, msg, wParam, lParam);
}