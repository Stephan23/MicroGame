#import "frame.h"

void init_screen()
{
    for (int y = 0; y < HIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            Keyboard.write(' ');
            pixel[y][x] = ' ';
        }
        Keyboard.write(KEY_RETURN);
    }
    for (int fx = 0; fx <= WIDTH; fx++)
        Keyboard.write(KEY_LEFT_ARROW);
    for (int fy = 0; fy < HIGHT; fy++)
        Keyboard.write(KEY_UP_ARROW);

    if (border)
        draw_border();
}

void draw_border()
{
    for (int i = 0; i < WIDTH + 2; i++)
    {
        Keyboard.write(BORDER_CHAR);
    }
    Keyboard.write(KEY_RETURN);
    for (int i = 0; i < HIGHT; i++)
    {
        Keyboard.write(BORDER_CHAR);
        Keyboard.write(KEY_DOWN_ARROW);
        Keyboard.write(KEY_LEFT_ARROW);
    }
    Keyboard.write('\n');
    for (int i = 0; i < WIDTH + 2; i++)
    {
        Keyboard.write(BORDER_CHAR);
    }
    for (int i = 0; i < HIGHT; i++)
    {
        Keyboard.write(KEY_UP_ARROW);
        Keyboard.write(BORDER_CHAR);
    }

    for (int i = 0; i < WIDTH+2; i++)
    {
        Keyboard.write(KEY_LEFT_ARROW);
    }
    Keyboard.write(KEY_UP_ARROW);

}

void change_pixel(int x, int y, char p)
{
    pixel[y][x] = p;
    if (border)
    {
        x++;
        y++;
    }
    while (x != px)
    {
        if (x - px < 0)
        {
            Keyboard.write(KEY_LEFT_ARROW);
            px--;
        }
        else
        {
            Keyboard.write(KEY_RIGHT_ARROW);
            px++;
        }
    }
    while (y != py)
    {
        if (y - py < 0)
        {
            Keyboard.write(KEY_UP_ARROW);
            py--;
        }
        else
        {
            Keyboard.write(KEY_DOWN_ARROW);
            py++;
        }
    }
    Keyboard.write(KEY_DELETE);
    Keyboard.write(p);
    px++;
}

void curser_homing()
{
    for (int fx = 0; fx < px; fx++)
        Keyboard.write(KEY_LEFT_ARROW);
    for (int fy = 0; fy < py; fy++)
        Keyboard.write(KEY_UP_ARROW);
    px = 0;
    py = 0;
}

void clear_screen()
{
    for (int y = 0; y < HIGHT; y++)
    {
        for(int x=0; x < WIDTH; x++)
        {
            change_pixel(x, y, ' ');
            pixel[y][x] = ' ';
        }
    }
}

void print_msg(int x, int y, char * msg)
{
    int i = 0;

    while (msg[i] != NULL && x + i < WIDTH)
    {
        change_pixel(x + i, y, msg[i]);
        i++;
    }
}
