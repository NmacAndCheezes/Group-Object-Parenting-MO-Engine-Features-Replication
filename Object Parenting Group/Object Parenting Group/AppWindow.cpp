/*MIT License

C++ 3D Game Tutorial Series (https://github.com/PardCode/CPP-3D-Game-Tutorial-Series)

Copyright (c) 2019-2022, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/


#include "AppWindow.h"
#include <Windows.h>
#include "Vector3D.h"
#include "Matrix4x4.h"
#include "AGameObjectManager.h"
#include "Cube.h"
#include "Rotator.h"
#include "Plane.h"
#include "EditorCamera.h"
#include "CameraManager.h"
#include "InputSystem.h"
#include "Math.h"
#include "GraphicsEngine.h"
#include "RenderSystem.h"
#include "DeviceContext.h"
#include "SwapChain.h"
#include "Editor UI/EditorUIManager.h"

AppWindow::AppWindow()
{
}


AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();

	EditorUIManager::initialize(this->m_hwnd);

	EditorCamera* eCam = new EditorCamera(this);
	eCam->SetPosition(3.78148, 6.62727, -4.19345);
	eCam->SetRotation(0.697706, -0.763867, 0);
	eCam->setViewType(0);
	CameraManager::get()->registerCamera(eCam);
	InputSystem::get()->addListner(eCam);

	m_swap_chain = GraphicsEngine::get()->getRenderSystem()->createSwapChain(this->m_hwnd, Width(), Height());


	TexturePtr m_wood_tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"./Assets/Textures/brick.png");
#if 1
	Rotator* rotator = new Rotator(Vector3D(1, 1, 1));
	Cube* cube;
	cube = new Cube(m_wood_tex);
	cube->transform()->SetPosition(Vector3D(1, 2, 0));
	cube->attachComponent(rotator);

	rotator = new Rotator(Vector3D(-1, -1, -1));
	cube = new Cube(m_wood_tex);
	cube->transform()->SetPosition(Vector3D(-1, 2, 0));
	cube->attachComponent(rotator);

	m_wood_tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"./Assets/Textures/sand.jpg");
	Plane* plane = new Plane(m_wood_tex);
	plane->transform()->SetRotation(Math::toRadians(180), 0, 0);
	plane->transform()->SetScale(Vector3D(100, 0, 100));
#endif
	
#if 0
	for (int i = 0; i < 50; i++)
	{
		float x = ((float(rand()) / float(RAND_MAX)) * 1.5f) - 0.75f;
		float y = ((float(rand()) / float(RAND_MAX)) * 1.5f) - 0.75f;
		float z = ((float(rand()) / float(RAND_MAX)) * 1.5f);


		Cube* cube = new Cube();
		cube->transform()->SetPosition(Vector3D(x, y, z));
		cube->transform()->SetRotation(Vector3D(0, 0, 0));
		cube->transform()->SetScale(Vector3D(0.2f, 0.2f, 0.2f));

		x = ((float(rand()) / float(RAND_MAX)) * ((1 - -1) + -1));
		y = ((float(rand()) / float(RAND_MAX)) * ((1 - -1) + -1));
		z = ((float(rand()) / float(RAND_MAX)) * ((1 - -1) + -1));
		Rotator* rotator = new Rotator(Vector3D(x, y, z));
		cube->attachComponent(rotator);
	}
#endif
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	//CLEAR THE RENDER TARGET 
	GraphicsEngine::get()->getRenderSystem()->getImmediateDeviceContext()->clearRenderTargetColor(
		this->m_swap_chain,
		0, 
		0.3f,
		0.4f, 
		1
	);
	//SET VIEWPORT OF RENDER TARGET IN WHICH WE HAVE TO DRAW
	GraphicsEngine::get()->getRenderSystem()->getImmediateDeviceContext()->setViewportSize(Width(), Height());

	//CameraManager::get()->getCurrentCamera()->updateCamera();
	InputSystem::get()->update();
	AGameObjectManager::get()->update();
	EditorUIManager::get()->update();
	m_swap_chain->present(false);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
}
