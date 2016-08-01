#include "game.h"

void loadLevel()
{
    getLevel(game.levelNo);
}

void loadPaddle(){
    vita2d_draw_rectangle(game.paddle.coord.x, game.paddle.coord.y, PADDLE_WIDTH, PADDLE_HEIGHT, ORANGE);
}
void loadBall(){
    if (game.ball.isMoving)
    {
        vita2d_draw_fill_circle(game.ball.coord.x, game.ball.coord.y, BALL_DIAMETER, RED);
    }else{
        vita2d_draw_fill_circle(game.ball.coord.x, game.ball.coord.y, BALL_DIAMETER, TRANS);
    }
}