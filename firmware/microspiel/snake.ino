// #define RIGHT 1
// #define UP 2
// #define LEFT 3
// #define DOWN 4
// #define FREE 0
// #define STOP 0
#import "snake.h"

void init_snake()
{
    clear_screen();
    for (int i = 0; i < HIGHT * WIDTH; i++)
    {
        x_snake[i] = FREE;
        y_snake[i] = FREE;
    }
    x_snake[0] = WIDTH / 2;
    y_snake[0] = HIGHT / 2;
    count = 0;
    broken = false;
    moving_direction = STOP;
    len_of_snake = 1;
    change_pixel(x_snake[count], y_snake[count], SNAKE_CHAR);

    int x = random(WIDTH - 1);
    int y = random(HIGHT - 1);
    while(pixel[y][x] != NO_SNAKE_CHAR)
    {
        x = random(WIDTH - 1);
        y = random(HIGHT);
    }
    change_pixel(x, y, APPLE);
    //print_msg(1 ,1 , "HALLO");
    curser_homing();
}


void update_snake()
{
    update_input();
    if (UP_KEY)
        moving_direction = UP;
    else if (DOWN_KEY)
        moving_direction = DOWN;
    else if (RIGHT_KEY)
        moving_direction = RIGHT;
    else if (LEFT_KEY)
        moving_direction = LEFT;

    if (!broken)
    {
        if (millis() - timestamp >= 250 - 250 / (HIGHT * WIDTH) * len_of_snake)
        {
            timestamp = millis();
            count = (count + 1)%(HIGHT * WIDTH);
            x_snake[count] = x_snake[(count + HIGHT * WIDTH - 1)%(HIGHT * WIDTH )];
            y_snake[count] = y_snake[(count + HIGHT * WIDTH - 1)%(HIGHT * WIDTH )];

            switch (moving_direction)
            {
                case LEFT:
                    x_snake[count] = x_snake[count] - 1;
                  break;
                case RIGHT:
                    x_snake[count] = x_snake[count] + 1;
                  break;
                case UP:
                    y_snake[count] = y_snake[count] - 1;
                  break;
                case DOWN:
                    y_snake[count] = y_snake[count] + 1;
                  break;
                default:
                  return;
            }
            if ((pixel[y_snake[count]][x_snake[count]] != APPLE && pixel[y_snake[count]][x_snake[count]] != NO_SNAKE_CHAR )|| y_snake[count] < 0 || y_snake[count] >= HIGHT || x_snake[count] < 0 || x_snake[count] >= WIDTH)
            {
                broken = true;
            }
            else
            {
                if (pixel[y_snake[count]][x_snake[count]] == APPLE)
                {
                    int x = random(WIDTH - 1), y = random(HIGHT);
                    while(pixel[y][x] != NO_SNAKE_CHAR)
                    {
                        x = random(WIDTH - 1);
                        y = random(HIGHT);
                    }
                    change_pixel(x, y, APPLE);
                    len_of_snake++;
                }
                else
                {
                    change_pixel(x_snake[((count + WIDTH * HIGHT) - len_of_snake)%(WIDTH * HIGHT)], y_snake[((count + WIDTH * HIGHT) - len_of_snake)%(WIDTH * HIGHT)], NO_SNAKE_CHAR);
                }
                change_pixel(x_snake[count], y_snake[count], SNAKE_CHAR);
            }
            curser_homing();
        }
    }
    else
    {
        if (A_KEY && B_KEY)
        {
            init_snake();
        }
    }
}
