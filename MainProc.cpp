#include "stdafx.h"


MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}


int MainProc::Init()
{
	bAct = true;

	SCENEMANAGER->Init();

	return 0;
}


int MainProc::Update(double deltaTime)
{
	INPUTMANAGER->Update();
	SCENEMANAGER->Update(deltaTime);

	if (INPUTMANAGER->IsKeyDown('A'))
	{
		ChangeWindow(FULLSCREEN);
	}

	if (INPUTMANAGER->IsKeyDown('S'))
	{
		ChangeWindow(WINDOWED);
	}
	return 0;
}


int MainProc::Render()
{
	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();

	IMAGEMANAGER->End();
	return 0;
}


int MainProc::Release()
{
	bAct = false;
	SCENEMANAGER->Release();

	ImageManager::ReleaseSingleton();
	InputManager::ReleaseSingleton();
	SceneManager::ReleaseSingleton();
	TextManager::ReleaseSingleton();
	SoundManager::ReleaseSingleton();

	return 0;
}


void MainProc::LostDevice()
{
	IMAGEMANAGER->LostDevice();
	TEXTMANAGER->LostDevice();
}


void MainProc::ResetDevice()
{
	IMAGEMANAGER->ResetDevice();
	TEXTMANAGER->ResetDevice();
}


void MainProc::ChangeWindow(SCREEN_MODE screenMode)
{
	SCREEN_MODE temp = windowMode;
	windowMode = screenMode;

	ShowWindow(hWnd, SW_HIDE);

	DWORD style = (screenMode == WINDOWED) ?
		WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX :
		WS_POPUP;
	DWORD exStyle = (screenMode == FULLSCREEN) ?
		WS_EX_APPWINDOW :
		0;

	SetWindowLongPtr(hWnd, GWL_STYLE, style);
	SetWindowLongPtr(hWnd, GWL_EXSTYLE, exStyle);

	LostDevice();
	HRESULT hr = lpd3dDevice->Reset(&MakeD3DPP(windowMode));
	ResetDevice();

	if (screenMode == FULLSCREEN)
	{
		MoveWindow(hWnd, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), false);
	}
	else if (screenMode == WINDOWED)
	{
		RECT rc = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(hWnd, NULL, 0, 0, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
	}

	ShowWindow(hWnd, SW_RESTORE);
}

D3DPRESENT_PARAMETERS MainProc::MakeD3DPP(SCREEN_MODE screenMode)
{
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = screenMode;

	return d3dpp;
}


// Get

BOOL MainProc::GetAct()
{
	return bAct;
}

SCREEN_MODE MainProc::GetScreenMode()
{
	return windowMode;
}
