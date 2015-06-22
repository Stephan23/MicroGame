#pragma once
#define SNAKE_CHAR '0'
#define NO_SNAKE_CHAR ' '
#define APPLE 'X'
#define BORDER_CHAR 'O'

#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4
#define FREE 0
#define STOP 0

int moving_direction;

int count = 0;
int len_of_snake = 1;
int x_snake[WIDTH * HIGHT];
int y_snake[WIDTH * HIGHT];
bool broken = false;
unsigned long timestamp;
