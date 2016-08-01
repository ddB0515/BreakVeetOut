#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/time.h>

#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <psp2/display.h>
#include <psp2/gxm.h>
#include <psp2/types.h>
#include <psp2/moduleinfo.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/dirent.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/sysmem.h>
#include <vita2d.h>

#include "utils.h"
#include "font_data.h"
#include "game.h"
#include "levels.h"
#include "bricks.h"

PSP2_MODULE_INFO(0, 0, "BreakVeetOut");

#ifndef NULL
#define NULL   ((void *) 0)
#endif

Game game;
Ball ball;
Paddle paddle;
LoadedLevel lvl;
vita2d_font *font = NULL;

void initGame();
int exitApp();

int main()
{
	initGame();
	srand(time(NULL));
	vita2d_init();
	vita2d_set_clear_color(GRAY);
	font = vita2d_load_font_mem(opensans, opensans_size);
	sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);
	SceCtrlData pad;
	memset(&pad, 0, sizeof(pad));

	while (!game.running) {
		sceCtrlPeekBufferPositive(0, &pad, 1);

		if ((pad.buttons & EXIT_COMBO) == EXIT_COMBO) break;
		
		
		// Move Left
		if (((pad.buttons & SCE_CTRL_LEFT) || pad.lx < 128 - ANALOG_THRESHOLD ||
		(pad.buttons & SCE_CTRL_LTRIGGER)) && game.paddle.coord.x > 0) {
			moveLeft();
		}
		// Move Right
		if ((pad.buttons & SCE_CTRL_RIGHT) || pad.lx > 128 + ANALOG_THRESHOLD ||
		(pad.buttons & SCE_CTRL_RTRIGGER)) && game.paddle.coord.x < SCREEN_W-PADDLE_WIDTH) {
			moveRight();
		}
		//BOT autoplay
		if (pad.buttons & SCE_CTRL_TRIANGLE) {
			game.bot=!game.bot;
		}

		if (pad.buttons & SCE_CTRL_CROSS && !game.ball.isMoving) {
			if (game.game_over)
			{
				initGame();
				game.ball.isMoving=true;
			}
			else if(game.nextLvl){
				game.nextLvl=0;
				game.levelNo++;
				if(game.levelNo==16)
					game.levelNo=1;
				game.levelLoaded=0;
				game.ball.isMoving=true;
			}
			else
			{
				game.ball.coord.x = game.paddle.coord.x+PADDLE_WIDTH/2;
				game.ball.coord.y = SCREEN_H-50;
				game.ball.isMoving=true;
			}
		}

		vita2d_start_drawing();
		vita2d_clear_screen();
		loadLevel();
		loadPaddle();
		loadBall();

		if (game.ball.isMoving)
		{
			startBall();
			if (game.level.noBricks==0 && game.levelNo <16)
			{
				game.ball.isMoving=0;
				game.nextLvl=1;
			}
		}
		else
		{
			if (game.game_over)
			{
				vita2d_font_draw_text(font, SCREEN_W/3+30, SCREEN_H/2-50, WHITE, 50, "GAME OVER");
				vita2d_font_draw_text(font, SCREEN_W/3+30, SCREEN_H/2 +30, WHITE, 30, "Press X to play again.");
			}else if(game.nextLvl){
				vita2d_font_draw_text(font, SCREEN_W/3-10, SCREEN_H/2 -30, WHITE, 50, "Level Complete");
				vita2d_font_draw_text(font, SCREEN_W/3, SCREEN_H/2 +30, WHITE, 30, "Press X to play next level.");
			}
			else {
				vita2d_font_draw_text(font, SCREEN_W/3+50, SCREEN_H/2 +30, WHITE, 30, "Press X to play.");
			}
		}
		// autoplay bot on triangle press (disabled by default
		if (game.bot)
		{
			if (game.ball.isMoving)
			{
				if (game.ball.coord.x<game.paddle.coord.x+PADDLE_WIDTH/2)
				{
					moveLeft();
				}else{
					moveRight();
				}
				if (game.level.noBricks==0 && game.levelNo <16)
				{
					game.ball.isMoving=0;
					game.nextLvl=1;
				}
			}
		}
		//lives
		char lives[32];
		sprintf(lives, "%s: %d", "Lives", game.lives);
		vita2d_font_draw_text(font, 10, SCREEN_H -25, WHITE, 20, lives);
		//lvl
		char lvl[32];
		sprintf(lvl, "%s %d/%d", "Level:", game.levelNo,15);
		vita2d_font_draw_text(font, SCREEN_W-120, SCREEN_H -25, WHITE, 20, lvl);

		vita2d_end_drawing();
		vita2d_swap_buffers();
	}

	return exitApp();
}

void initGame(){
	game.bot=0;
	game.running = 0;
	game.game_over = 0;
	game.levelNo = 1;
	game.nextLvl = 0;
	game.isMenuShown = 1;
	game.lives = NUM_LIVES;
	game.levelLoaded = 0;
	game.level = lvl;

	game.ball = ball;
	game.ball.x_speed = BALL_SPEED;
	game.ball.y_speed = BALL_SPEED;
	game.ball.isMoving=false;
	game.ball.coord.x = SCREEN_W/2;
	game.ball.coord.y = SCREEN_H-50;

	game.paddle = paddle;
	game.paddle.coord.x = SCREEN_W/2-75;
	game.paddle.coord.y = SCREEN_H-30;
}

int exitApp(){
	vita2d_fini();
	sceKernelExitProcess(0);
	return 0;
}
