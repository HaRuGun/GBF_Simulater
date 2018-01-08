#pragma once

enum BATTLE_PHASE
{
	NONE = 0,
	READY,
	START_PHASE,
	ACTION_PHASE,
	BEFORE_ATTACK_PHASE,
	ATTACK_PHASE,
	ENEMY_PHASE,
	END_PHASE,
	FINISH
};

class MainBattle
{
protected:
	BATTLE_PHASE phase;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	MainBattle() {}
	virtual ~MainBattle() {}
};

