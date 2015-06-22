#define WIDTH 14
#define HIGHT 7

#import "frame.h"
#import "input.h"
#import "snake.h"





void setup()
{
    Keyboard.begin();
    delay(1000);
    randomSeed(analogRead(0));
    init_input();
    init_screen();
    init_snake();
}

void loop()
{
    update_snake();
}



