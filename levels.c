#include "game.h"
#include "paddle.h"
#include "levels.h"
#include "utils.h"
#include "bricks.h"

int level1[5][10] = {  
 {1, 0, 1, 2, 3, 3, 3, 0, 4, 0}, 
 {1, 0, 1, 2, 0, 3, 0, 0, 4, 0}, 
 {1, 0, 1, 2, 0, 3, 0, 4, 0, 4}, 
 {0, 1, 0, 2, 0, 3, 0, 4, 4, 4}, 
 {0, 1, 0, 2, 0, 3, 0, 4, 0, 4}, 
};

int level2[5][10] = {  
 {0, 2, 0, 0, 0, 0, 0, 0, 2, 0}, 
 {2, 1, 2, 0, 3, 3, 0, 2, 1, 2}, 
 {2, 1, 2, 0, 3, 3, 0, 2, 1, 2}, 
 {2, 1, 2, 0, 3, 3, 0, 2, 1, 2}, 
 {0, 2, 0, 0, 0, 0, 0, 0, 2, 0}, 
};


int level3[5][10] = {  
 {0, 3, 0, 3, 0, 3, 0, 3, 0, 3}, 
 {4, 0, 4, 0, 4, 0, 4, 0, 4, 0}, 
 {0, 3, 0, 3, 0, 3, 0, 3, 0, 3}, 
 {4, 0, 4, 0, 4, 0, 4, 0, 4, 0}, 
 {0, 3, 0, 3, 0, 3, 0, 3, 0, 3}, 
};

int level4[5][10] = {  
 {1, 0, 1, 0, 4, 4, 0, 1, 0, 1}, 
 {1, 0, 1, 0, 4, 4, 0, 1, 0, 1}, 
 {0, 1, 0, 0, 4, 4, 0, 0, 1, 0}, 
 {1, 0, 1, 0, 4, 4, 0, 1, 0, 1}, 
 {1, 0, 1, 0, 4, 4, 0, 1, 0, 1}, 
};

int level5[5][10] = {  
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
 {1, 4, 4, 4, 4, 4, 4, 4, 4, 1}, 
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
};

int level6[5][10] = {  
 {2, 2, 0, 1, 0, 0, 1, 0, 2, 2}, 
 {2, 2, 0, 1, 1, 1, 1, 0, 2, 2}, 
 {0, 0, 0, 0, 4, 4, 0, 0, 0, 0}, 
 {2, 2, 0, 1, 1, 1, 1, 0, 2, 2}, 
 {2, 2, 0, 1, 0, 0, 1, 0, 2, 2}, 
};

int level7[5][10] = {  
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
 {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, 
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
 {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, 
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
};

int level8[5][10] = {  
 {1, 2, 0, 0, 2, 1, 0, 0, 2, 1}, 
 {1, 2, 0, 0, 2, 1, 0, 0, 2, 1}, 
 {1, 2, 0, 0, 2, 1, 0, 0, 2, 1}, 
 {1, 2, 0, 0, 2, 1, 0, 0, 2, 1}, 
 {1, 2, 0, 0, 2, 1, 0, 0, 2, 1}, 
};

int level9[5][10] = {  
 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
 {4, 0, 0, 0, 0, 0, 0, 0, 0, 4}, 
 {4, 0, 2, 2, 0, 0, 2, 2, 0, 4}, 
 {4, 0, 0, 0, 0, 0, 0, 0, 0, 4}, 
 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
};

int level10[5][10] = {  
 {3, 0, 3, 0, 0, 0, 0, 1, 0, 1}, 
 {3, 3, 3, 0, 4, 4, 0, 1, 1, 1}, 
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
 {1, 1, 1, 0, 4, 4, 0, 3, 3, 3}, 
 {1, 0, 1, 0, 0, 0, 0, 3, 0, 3}, 
};

int level11[5][10] = {  
 {2, 2, 2, 0, 4, 4, 0, 2, 2, 2}, 
 {0, 0, 2, 0, 4, 4, 0, 2, 0, 0}, 
 {0, 0, 2, 0, 0, 0, 0, 2, 0, 0}, 
 {0, 0, 2, 0, 4, 4, 0, 2, 0, 0}, 
 {2, 2, 2, 0, 4, 4, 0, 2, 2, 2}, 
};

int level12[5][10] = {  
 {1, 1, 0, 2, 0, 0, 2, 0, 1, 1}, 
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
 {4, 0, 1, 1, 1, 1, 1, 1, 0, 4}, 
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
 {1, 1, 0, 2, 0, 0, 2, 0, 1, 1}, 
};

int level13[5][10] = {  
 {0, 4, 4, 4, 4, 4, 4, 4, 4, 0}, 
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
 {0, 0, 0, 0, 4, 4, 0, 0, 0, 0}, 
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
 {0, 4, 4, 4, 4, 4, 4, 4, 4, 0}, 
};

int level14[5][10] = {  
 {1, 1, 0, 0, 4, 4, 0, 0, 1, 1}, 
 {0, 0, 1, 1, 0, 0, 1, 1, 0, 0}, 
 {2, 2, 0, 0, 1, 1, 0, 0, 2, 2}, 
 {0, 0, 1, 1, 0, 0, 1, 1, 0, 0}, 
 {1, 1, 0, 0, 4, 4, 0, 0, 1, 1}, 
};

int level15[5][10] = {  
 {2, 2, 0, 0, 3, 0, 3, 0, 4, 4}, 
 {2, 0, 2, 0, 3, 0, 3, 0, 4, 0}, 
 {2, 2, 0, 0, 0, 3, 0, 0, 4, 4}, 
 {2, 0, 2, 0, 0, 3, 0, 0, 4, 0}, 
 {2, 2, 0, 0, 0, 3, 0, 0, 4, 4}, 
};

int temp[5][10] = {{0}};

void getLevel(int num)
{
    setLevel(num);
    int i, j, noBlocks=0;

    for(j = 4; j >= 0; j --) 
    {
        for(i = 0; i < 10; i ++) 
        {
            int x = temp[j][i];
            
            if(x>0)
                noBlocks++;

            int xx =i*BLOCK_WIDTH;
            int yy = j*BLOCK_HEIGHT;
            Brick b;
            switch(x){
                case 99:
                        b.rect.coord_upper_left.x=xx;
                        b.rect.coord_upper_left.y=yy;
                        b.rect.coord_lower_right.x=xx+BLOCK_WIDTH;
                        b.rect.coord_lower_right.y=yy+BLOCK_HEIGHT;
                        b.state=1;
                        b.hits=1;
                        b.block_type=x;
                        game.level.board[j][i]=b;
                        vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, WHITE);
                break;
                case 0:
                        b.rect.coord_upper_left.x=xx;
                        b.rect.coord_upper_left.y=yy;
                        b.rect.coord_lower_right.x=xx+BLOCK_WIDTH;
                        b.rect.coord_lower_right.y=yy+BLOCK_HEIGHT;
                        b.state=0;
                        b.hits=0;
                        b.block_type=x;
                        game.level.board[j][i]=b;
                        vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, TRANS);
                break;

                case 1:
                        b.rect.coord_upper_left.x=xx;
                        b.rect.coord_upper_left.y=yy;
                        b.rect.coord_lower_right.x=xx+BLOCK_WIDTH;
                        b.rect.coord_lower_right.y=yy+BLOCK_HEIGHT;
                        b.state=1;
                        b.hits=1;
                        b.block_type=x;
                        game.level.board[j][i]=b;
                        vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, BLUE);
                break;
                
                case 2:
                        b.rect.coord_upper_left.x=xx;
                        b.rect.coord_upper_left.y=yy;
                        b.rect.coord_lower_right.x=xx+BLOCK_WIDTH;
                        b.rect.coord_lower_right.y=yy+BLOCK_HEIGHT;
                        b.state=1;
                        b.hits=2;
                        b.block_type=x;
                        game.level.board[j][i]=b;
                        vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, RED);
                break;

                case 3:
                        b.rect.coord_upper_left.x=xx;
                        b.rect.coord_upper_left.y=yy;
                        b.rect.coord_lower_right.x=xx+BLOCK_WIDTH;
                        b.rect.coord_lower_right.y=yy+BLOCK_HEIGHT;
                        b.state=1;
                        b.hits=1;
                        b.block_type=x;
                        game.level.board[j][i]=b;
                        vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, GREEN);                       
                break;

                case 4:
                        b.rect.coord_upper_left.x=xx;
                        b.rect.coord_upper_left.y=yy;
                        b.rect.coord_lower_right.x=xx+BLOCK_WIDTH;
                        b.rect.coord_lower_right.y=yy+BLOCK_HEIGHT;
                        b.state=1;
                        b.hits=2;
                        b.block_type=x;
                        game.level.board[j][i]=b;
                        vita2d_draw_rectangle(b.rect.coord_upper_left.x, b.rect.coord_upper_left.y, BLOCK_WIDTH, BLOCK_HEIGHT, YELLOW);
                break;
            }

        }
    }
    game.level.noBricks=noBlocks;
    game.levelLoaded = 1;
}

void setLevel(int num){
    if (game.levelLoaded!=1)
    {
        switch(num)
            {
                case 1:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level1, 5 * 10 * sizeof(int));
                break;
                case 2:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level2, 5 * 10 * sizeof(int));
                break;
                case 3:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level3, 5 * 10 * sizeof(int));
                break;
                case 4:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level4, 5 * 10 * sizeof(int));
                break;
                case 5:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level5, 5 * 10 * sizeof(int));
                break;
                case 6:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level6, 5 * 10 * sizeof(int));
                break;
                case 7:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level7, 5 * 10 * sizeof(int));
                break;
                case 8:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level8, 5 * 10 * sizeof(int));
                break;
                case 9:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level9, 5 * 10 * sizeof(int));
                break;
                case 10:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level10, 5 * 10 * sizeof(int));
                break;
                case 11:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level11, 5 * 10 * sizeof(int));
                break;
                case 12:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level12, 5 * 10 * sizeof(int));
                break;
                case 13:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level13, 5 * 10 * sizeof(int));
                break;
                case 14:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level14, 5 * 10 * sizeof(int));
                break;
                case 15:
                    memset(temp, 0, sizeof(temp[0][0]) * 5 * 10);
                    memcpy(temp, level15, 5 * 10 * sizeof(int));
                break;
            }
    }
}