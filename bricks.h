#ifndef __BRICKS_H__
#define __BRICKS_H__

typedef struct {
  int x, y;
} brick_coordinate;

typedef struct
{
  brick_coordinate coord_upper_left; //uper-left
  brick_coordinate coord_lower_right; //lower-right
} rectangle_t;

typedef struct {
  rectangle_t rect;
  int state; //visible-inv
  int hits;
  int block_type;
} Brick;

#endif
