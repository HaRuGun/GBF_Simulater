#pragma once

enum BATTLE_PHASE
{
	NONE = 0,
	READY,
	START_PHASE,
	ACTION_PHASE,
	ATTACK_PHASE,
	ENEMY_PHASE,
	END_PHASE,
	FINISH
};

class MainBattle
{
protected:
	BATTLE_PHASE phase;
	UMonster *Boss;

public:
	void Init();
	void Update(double deltaTime);
	void Render(double deltaTime);
	void Release();

	void PhaseReady();
	void PhaseStart();
	void PhaseAction();
	void PhaseAttack();
	void PhaseEnemy();
	void PhaseEnd();
	void PhaseFinish();

	MainBattle() {}
	virtual ~MainBattle() {}
};

