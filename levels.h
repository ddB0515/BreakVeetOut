#ifndef __LEVELS_H__
#define __LEVELS_H__

#include "utils.h"
#include "bricks.h"

extern int level1[5][10];
extern int level2[5][10];
extern int level3[5][10];
extern int level4[5][10];
extern int level5[5][10];
extern int level6[5][10];
extern int level7[5][10];
extern int level8[5][10];
extern int level9[5][10];
extern int level10[5][10];
extern int level11[5][10];
extern int level12[5][10];
extern int level13[5][10];
extern int level14[5][10];
extern int level15[5][10];

extern int temp[5][10];

typedef struct  {
	int bricks[5][10];
    Brick board[5][10];
    int noBricks;
} LoadedLevel;

void getLevel(int num);

#endif
