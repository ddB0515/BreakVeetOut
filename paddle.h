#ifndef __PADDLE_H__
#define __PADDLE_H__


typedef struct {
  int x, y;
} paddle_coordinate;

typedef struct {
	// State
	paddle_coordinate coord;
	float speed;

} Paddle;

void moveLeft();
void moveRight();
#endif 