#include "paddle.h"
#include "game.h"
#include "utils.h"

void moveLeft(){
	game.paddle.coord.x-=PADDLE_SPEED;
			if (!game.ball.isMoving)
				game.ball.coord.x-=PADDLE_SPEED;
}

void moveRight(){
	game.paddle.coord.x+=PADDLE_SPEED;
			if (!game.ball.isMoving)
				game.ball.coord.x+=PADDLE_SPEED;
}