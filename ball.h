#ifndef __BALL_H__
#define __BALL_H__
#include <stdbool.h>
#include "bricks.h"

typedef struct {
  int x, y;
} ball_coordinate;

typedef struct {
  int l, t,r,b;
} ball_points;

typedef struct {
	ball_coordinate coord;
	ball_points ballpoints;
	int x_speed;
	int y_speed;
	int isMoving;
} Ball;

void startBall();
void moveBall();
bool checkBallCollisions();
void checkBlockCollisions();
void handleBlockCollision(Brick b, int j, int i);
bool isInsideBrick(int x, int y, brick_coordinate rect);
int  isInsideBrickStructured (ball_coordinate pPoint, rectangle_t pRect);


#endif 