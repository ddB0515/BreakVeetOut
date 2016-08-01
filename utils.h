#ifndef __UTILS_H__
#define __UTILS_H__

#define SCREEN_W 960
#define SCREEN_H 544

#define ANALOG_THRESHOLD 100
#define EXIT_COMBO (SCE_CTRL_START | SCE_CTRL_SELECT)

#define TRANS   RGBA8(  0,   0,   0, 0)
#define BLACK   RGBA8(  0,   0,   0, 255)
#define WHITE   RGBA8(255, 255, 255, 255)
#define GREEN   RGBA8(  0, 255,   0, 255)
#define RED     RGBA8(255,   0,   0, 255)
#define BLUE    RGBA8(  0,   0, 255, 255)
#define GRAY    RGBA8( 70,  70,  70, 255)
#define CYAN    RGBA8(  0, 255, 255, 255)
#define ORANGE  RGBA8(255, 165,	  0, 255)
#define YELLOW  RGBA8(255, 255,	  0, 255)

// Dimensions of a paddle //
#define PADDLE_WIDTH   150
#define PADDLE_HEIGHT  30

// Dimensions of a block //
#define BLOCK_WIDTH  96
#define BLOCK_HEIGHT 30
#define PADDLE_PADDING 0

// Paddle speed //
#define PADDLE_SPEED 7

// Diameter of the ball //
#define BALL_DIAMETER 20
#define BALL_SPEED 5 //initial speed for moving top left


// Maximum number of times the player can miss the ball //
#define NUM_LIVES 3

// Number of levels, increase this value to add new levels //
#define NUM_LEVELS 3

#endif 
