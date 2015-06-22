#import "input.h"
void init_input()
{
    pinMode(MY_KEY_UP, INPUT_PULLUP);
    pinMode(MY_KEY_DOWN, INPUT_PULLUP);
    pinMode(MY_KEY_RIGHT, INPUT_PULLUP);
    pinMode(MY_KEY_LEFT, INPUT_PULLUP);
    pinMode(MY_KEY_A, INPUT_PULLUP);
    pinMode(MY_KEY_B, INPUT_PULLUP);
}


void update_input()
{
    UP_KEY = !digitalRead(MY_KEY_UP);
    DOWN_KEY = !digitalRead(MY_KEY_DOWN);
    RIGHT_KEY = !digitalRead(MY_KEY_RIGHT);
    LEFT_KEY = !digitalRead(MY_KEY_LEFT);
    A_KEY = !digitalRead(MY_KEY_A);
    B_KEY = !digitalRead(MY_KEY_B);
}
