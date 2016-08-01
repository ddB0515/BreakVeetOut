#include "ball.h"
#include <vita2d.h>
#include "game.h"
#include "paddle.h"
#include "levels.h"
#include "utils.h"
#include "bricks.h"

void startBall(){

	moveBall();
	if (checkBallCollisions())
	{
		if (game.ball.coord.x < game.paddle.coord.x + PADDLE_WIDTH/3)
		{
			game.ball.x_speed = game.ball.y_speed;
			game.ball.y_speed = -game.ball.y_speed;
		}
		else if (game.ball.coord.x > game.paddle.coord.x + 2*(PADDLE_WIDTH/3))
		{
			game.ball.x_speed = -game.ball.y_speed;
			game.ball.y_speed = -game.ball.y_speed ;
		}else{
			game.ball.y_speed = -game.ball.y_speed;
		}
		
	}

	// Check for collisions with blocks //
	checkBlockCollisions();
}

// Check to see if a point is within a rectangle //
bool isInsideBrick(int x, int y, brick_coordinate rect)
{
	if ( (x >= rect.x) && (x <= rect.x + BLOCK_WIDTH) && 
		 (y >= rect.y) && (y <= rect.y + BLOCK_HEIGHT) )
	{
		return true;
	}
	return false;
}

int isInsideBrickStructured (ball_coordinate pPoint, rectangle_t pRect)
{
	return ((pPoint.x >= pRect.coord_upper_left.x ) &&
	(pPoint.x <= pRect.coord_lower_right.x) &&
	(pPoint.y >= pRect.coord_upper_left.y ) &&
	(pPoint.y <= pRect.coord_lower_right.y));
 
}

void moveBall(){
	game.ball.coord.x += game.ball.x_speed;
	game.ball.coord.y -= game.ball.y_speed;

	//left
	if (game.ball.coord.x <= 0 + BALL_DIAMETER/2)
	{
		game.ball.x_speed = -game.ball.x_speed;
	}
	//top
	if (game.ball.coord.y <= 0 + BALL_DIAMETER/2)
	{
		game.ball.y_speed = -game.ball.y_speed ;
	}
	//right
	if (game.ball.coord.x >= SCREEN_W- BALL_DIAMETER/2)
	{
		game.ball.x_speed = -game.ball.x_speed ;
	}

	// Check to see if ball has passed the paddle //
	if ( game.ball.coord.y + BALL_DIAMETER/2  >= SCREEN_H )
	{
		game.lives-=1;
		game.ball.x_speed  = BALL_SPEED;
		game.ball.y_speed  = BALL_SPEED;
		game.ball.isMoving = false;

		if (game.lives == 0)
		{
			game.game_over = true;
			game.ball.isMoving = false;
		}
	}

}
// Check to see if the ball is going to hit the paddle //
bool checkBallCollisions()
{
	// Check to see if ball is in Y range of the player's paddle. //
	// We check its speed to see if it's even moving towards the player's paddle. //
	if ( (BALL_SPEED > 0) && (game.ball.coord.y + BALL_DIAMETER/2 >= game.paddle.coord.y) && 
		 (game.ball.coord.y + BALL_DIAMETER/2 <= game.paddle.coord.y + PADDLE_HEIGHT) )        // side hit
	{
		// If ball is in the X range of the paddle, return true. //
		if ( (game.ball.coord.x + BALL_DIAMETER/2 <= game.paddle.coord.x + PADDLE_WIDTH) && (game.ball.coord.x + BALL_DIAMETER/2 >= game.paddle.coord.x) )
		{
			return true;
		}
	}
	return false;
}

void checkBlockCollisions()
{
	// collision points 
	int left_x   = game.ball.coord.x - BALL_DIAMETER/2;
	int left_y   = game.ball.coord.y;
	int right_x  = game.ball.coord.x + BALL_DIAMETER/2;
	int right_y  = game.ball.coord.y;
	int top_x    = game.ball.coord.x;
	int top_y    = game.ball.coord.y - BALL_DIAMETER/2;
	int bottom_x = game.ball.coord.x;
	int bottom_y = game.ball.coord.y + BALL_DIAMETER/2;

	bool top = false;
	bool bottom = false;
	bool left = false;
	bool right = false;

	if (game.ball.ballpoints.t <= 5*BLOCK_HEIGHT)
	{
		int i, j;
		for(j = 4; j >= 0; j --) 
		{
	    	for(i = 0; i < 10; i ++) 
	    	{
	    		Brick b = game.level.board[j][i];
				// top //
				if ( isInsideBrick(top_x, top_y, b.rect.coord_upper_left) && b.state == 1)
				{
					top = true;
					handleBlockCollision(b ,j , i );
				}
				// bottom //
				if ( isInsideBrick(bottom_x, bottom_y,  b.rect.coord_upper_left)  && b.state == 1)
				{
					bottom = true;
					handleBlockCollision(b ,j , i );
				}
				// left //
				if ( isInsideBrick(left_x, left_y,  b.rect.coord_upper_left)  && b.state == 1)
				{
					left = true;
					handleBlockCollision(b ,j , i );
				}
				// right //
				if ( isInsideBrick(right_x, right_y,  b.rect.coord_upper_left)  && b.state == 1)
				{
					right = true;
					handleBlockCollision(b ,j , i );
				}
				
				if (top)
				{
					game.ball.y_speed = -game.ball.y_speed;
				}
				if (bottom)
				{
					game.ball.y_speed = -game.ball.y_speed ;
				}
				if (left)
				{
					game.ball.x_speed = -game.ball.x_speed ;
				}
				if (right)
				{
					game.ball.x_speed = -game.ball.x_speed ;
				}
				top = false;
				bottom = false;
				left = false;
				right = false;
	    	}
	    }
	}

	
}

void handleBlockCollision(Brick b, int j, int i)
{
	//b.hits--;

	// If num_hits is 0, the block needs to be erased //
	if (b.state)
	{
		if (b.hits>1)
		{
			b.hits--;
			temp[j][i]=99;
			vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, WHITE);
		}else
		{
			//handle collision
			b.state=false;
			b.block_type=0;
			vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, TRANS);
			temp[j][i]=0;
		}
		
	}
}