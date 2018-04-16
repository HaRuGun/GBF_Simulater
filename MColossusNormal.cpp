#include "stdafx.h"
#include "MColossusNormal.h"

#define COL_HEAD_MAT		matrix(1, 1, colDeath.x + 149, colDeath.y - 191, 0, 0)
#define COL_BODY_MAT		matrix(1, 1, colDeath.x + 45, colDeath.y - 28, 0, 0)
#define COL_RSHOULDER_MAT	matrix(1, 1, colDeath.x - 8, colDeath.y - 167, 0, 0)
#define COL_RARM_MAT		matrix(1, 1, colDeath.x - 128, colDeath.y - 136, 0, 0)
#define COL_SWORD_MAT		matrix(1, 1, colDeath.x - 5, colDeath.y + 79, 0, 0)
#define COL_HANDLE_MAT		matrix(1, 1, colDeath.x - 240, colDeath.y - 118, 0, 0)
#define COL_LSHOULDER_MAT	matrix(1, 1, colDeath.x + 174, colDeath.y - 87, 0, 0)
#define COL_LHAND_MAT		matrix(1, 1, colDeath.x + 237, colDeath.y + 24, 0, -5)
#define COL_RLEG_MAT		matrix(1, 1, colDeath.x + 6, colDeath.y + 103, 0, 0)
#define COL_FOOT_MAT		matrix(1, 1, colDeath.x - 25, colDeath.y + 171, 0, 0)


void MColossusNormal::Init()
{
	ATLASMANAGER->SetAtlas("COLOSUSS", "./txt/Colosuss.txt", "./Texture/Colosuss.png");
	colDeath = { 1, 1, 360, 360, 0, 0 };
	colbody = COL_BODY_MAT;
	colhead = COL_HEAD_MAT;
	colLshoulder = COL_LSHOULDER_MAT;
	colRshoulder = COL_RSHOULDER_MAT;
	colRArm = COL_RARM_MAT;
	colRleg = COL_RLEG_MAT;
	colHandle = COL_HANDLE_MAT;
	colLHand = COL_LHAND_MAT;
	colSword = COL_SWORD_MAT;
	colFoot = COL_FOOT_MAT;

	frame.wCount = 0;
	a_State = MONSTER_ANIME_STATE::M_IDLE;
}

void MColossusNormal::Update(double deltaTime)
{
	switch (a_State)
	{
	case M_IDLE:

		break;
	case M_ATTACK:
		break;
	case M_HURT:
		break;
	default:
		break;
	}
}

void MColossusNormal::Render(double deltaTime)
{
	switch (a_State)
	{
	case M_IDLE:
		IdleAnime();
		break;
	case M_ATTACK:
		break;
	case M_HURT:
		break;
	default:
		break;
	}
}

void MColossusNormal::Release()
{

}

void MColossusNormal::IdleAnime()
{
	if (frame.wCount >= 0 && frame.wCount <= 29)
	{
		//head
		{
			colhead.x += 0.1;
			colhead.y += 0.1;
			colhead.direction += 0.05;
		}
		//Body
		{
			colbody.direction -= 0.05;
		}
		//RightSoulder
		{
			colRshoulder.direction += 0.05;
		}
		//RightArm
		{
			colRArm.direction += 0.1;
			colRArm.x -= 0.1;
			colRArm.y -= 0.1;
		}
		//Sword
		{
			colSword.x -= 0.4;
			colSword.direction += 0.05;
		}
		//Handle
		{
			colHandle.x -= 0.4;
			colHandle.direction += 0.05;
		}
		//LeftShoulder
		{
			colLshoulder.x -= 0.1;
			colLshoulder.y -= 0.1;
		}
		//LeftHand
		{
			colLHand.x -= 0.1;
			colLHand.y -= 0.2;
			colLHand.direction += 0.2;
		}
		//RightLeg
		{
			colRleg.x += 0.05;
			colRleg.y -= 0.05;
		}
		//Foot
		{
			colFoot.direction += 0.05;
		}
	}
	if (frame.wCount >= 50 && frame.wCount <= 79)
	{
		//head
		{
			colhead.x -= 0.1;
			colhead.y += 0.1;
			colhead.direction += 0.05;
		}
		//Body
		{
			colbody.width += 0.001;
		}
		//RightSoulder
		{
			colRshoulder.direction += 0.4;
			colRshoulder.y -= 0.2;
		}
		//RightArm
		{
			colRArm.direction -= 0.4;
			colRArm.y -= 0.4;
		}
		//Sword
		{
			colSword.x += 1;
			colSword.y -= 1.5;
			colSword.direction -= 0.4;
		}
		//Handle
		{
			colHandle.x += 0.1;
			//colHandle.y -= 1.5;
			colHandle.direction -= 0.4;
		}
		//LeftShoulder
		{
			colLshoulder.direction -= 0.05;
			colLshoulder.x -= 0.2;
			colLshoulder.y -= 0.2;
		}
		//LeftHand
		{
			colLHand.x -= 0.2;
			colLHand.y -= 0.2;
			colLHand.direction += 0.2;
		}
		//RightLeg
		{
			colRleg.x -= 0.1;
		}
		//Foot
		{
			colFoot.direction += 0.05;
		}
	}
	if (frame.wCount >= 90 && frame.wCount <= 150)
	{
		//head
		{
			colhead.y -= 0.1;
			if (colhead.direction > 0)
				colhead.direction -= 0.2;
		}
		//Body
		{
			colbody.width -= 0.0005;
			if(colbody.direction < 0)
				colbody.direction += 0.05;
		}
		//RightSoulder
		{
			if (colRshoulder.direction > 0)
				colRshoulder.direction -= 0.7;
			colRshoulder.y += 0.1;
		}
		//RightArm
		{
			if (colRArm.direction < 0)
				colRArm.direction += 0.4;
			colRArm.y += 0.25;
			colRArm.x += 0.05;
		}
		//Sword
		{
			colSword.x -= 0.3;
			colSword.y += 0.75;

			if(colSword.direction < 0)
				colSword.direction += 0.19;
		}
		//Handle
		{
			colHandle.x += 0.15;
			//colHandle.y += 0.75;

			if (colHandle.direction < 0)
				colHandle.direction += 0.19;
		}
		//LeftShoulder
		{
			if(colLshoulder.direction < 0)
				colLshoulder.direction += 0.05;
			colLshoulder.x += 0.15;
			colLshoulder.y += 0.15;
		}
		//LeftHand
		{
			if (colLHand.direction > COL_LHAND_MAT.direction)
				colLHand.direction -= 0.2;
			colLHand.x += 0.15;
			colLHand.y += 0.2;
		}
		//RightLeg
		{
			colRleg.x += 0.025;
			colRleg.y += 0.025;
		}
		//Foot
		{
			if(colFoot.direction > 0)
				colFoot.direction -= 0.05;
		}
	}
	if (frame.wCount > 160)
	{
		colhead = COL_HEAD_MAT;
		colbody = COL_BODY_MAT;
		colRshoulder = COL_RSHOULDER_MAT;
		colRArm = COL_RARM_MAT;
		colSword = COL_SWORD_MAT;
		colHandle = COL_HANDLE_MAT;
		colLshoulder = COL_LSHOULDER_MAT;
		colLHand = COL_LHAND_MAT;
		colRleg = COL_RLEG_MAT;
		colFoot = COL_FOOT_MAT;
		frame.wCount = 0;
	}
	frame.wCount++;

	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSLEFTSHOULDER", colLshoulder);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSLEFTHAND", colLHand);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSHANDLE", colHandle);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSHEAD", colhead);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSBODY", colbody);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSRIGHTSHOULDER", colRshoulder);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSRIGHTARM", colRArm);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSFOOT", colFoot);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSRIGHTLEG", colRleg);
	IMAGEMANAGER->DrawAtlasImage("COLOSUSS", "COLOSUSSSWORD", colSword);
}

MColossusNormal::MColossusNormal()
{
}


MColossusNormal::~MColossusNormal()
{
}
