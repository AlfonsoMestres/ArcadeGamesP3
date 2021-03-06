#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Point.h"

struct SDL_Texture;

enum PlayerState
{
	Crouching,
	Jumping,
	Standing,
	Attacking,
	Idle
};

enum PlayerAttack 
{
	Waiting,
	PunchR,
	CPunchR,
	PunchL,
	CPunchL,
	KickR,
	KickL
};

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool start_enabled = true);
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	void repeatUntilFinished();
	void UpdateSpecialAttack();
	void ThrowRangedAttack(Animation& specialAnimation, int attackDuration);
	bool CleanUp();

public:
	int specialXMod, rngdAtkMaxDistTraveled;
	PlayerState nextPlayerState;
	PlayerState playerState = Standing;
	PlayerAttack playerAttack;
	SDL_Texture* graphics = nullptr;
	SDL_Rect player;
	SDL_Rect specialAttack;
	Animation* onGoingAnimation = nullptr;
	Animation* onGoingSpecial = nullptr;
	Animation idle;
	Animation backward;
	Animation forward;
	Animation jumpNormal;
	Animation lightPunch;
	Animation heavyPunch;
	Animation crouch;
	Animation crouchedLightPunch;
	Animation crouchedHeavyPunch;
	Animation throwHadouken;
	Animation hadouken;
	iPoint playerPosition;
	iPoint specPosition;
};

#endif // __MODULEPLAYER_H__