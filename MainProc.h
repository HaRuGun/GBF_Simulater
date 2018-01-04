#pragma once


enum SCREEN_MODE
{
	FULLSCREEN = 0,
	WINDOWED
};

class MainProc
{
private:
	BOOL bAct;

	SCREEN_MODE windowMode;

public:
	int Init();
	int Update(double deltaTime);
	int Render();
	int Release();

	void LostDevice();
	void ResetDevice();
	void ChangeWindow(SCREEN_MODE screenMode);
	D3DPRESENT_PARAMETERS MakeD3DPP(SCREEN_MODE screenMode);

	BOOL GetAct();
	SCREEN_MODE GetScreenMode();

	MainProc();
	virtual ~MainProc();
};