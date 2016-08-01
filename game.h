#ifndef __GAME_H__
#define __GAME_H__

#include <vita2d.h>
#include "ball.h"
#include "paddle.h"
#include "levels.h"
#include "bricks.h"
#include "game.h"
#include "utils.h"

typedef struct {
	// State
	int bot;
	int running;
	int isMenuShown;
	int game_over;
	int levelNo;
	int nextLvl;
	int levelLoaded;
	LoadedLevel level;
	int lives;
	Ball ball;
	Paddle paddle;
} Game;

extern Game game;

void loadLevel();
void loadPaddle();
void loadBall();

#endif 