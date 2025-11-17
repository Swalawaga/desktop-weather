#include <iostream>
#include <raylib.h>
#include <math.h>
#include "sun.h"

#define SIZE 1000
#define RAYS 100
#define SPEED .05

Sun::Sun() {
//   x = GetRandomValue(0,GetScreenWidth());
  x = GetScreenWidth()-100;
  y = -20;
}

void Sun::draw(int iterator) {
    BeginBlendMode(BLEND_ADDITIVE);
    DrawCircleGradient(x,y,SIZE,(Color){255, 236, 80, 255},BLANK);
    DrawCircleGradient(x,y,SIZE*1.3,(Color){255, 236, 80, 200},BLANK);
    for(int i = 0; i < RAYS/2; i ++){
        DrawRectanglePro((Rectangle){x,y,10000,SIZE/10},(Vector2){0,0},SPEED*(float)iterator+(360/(RAYS/2))*i,(Color){255, 236, 80, 2});
    }
    for(int i = 0; i < RAYS/2; i ++){
        DrawRectanglePro((Rectangle){x,y,10000,SIZE/10},(Vector2){0,0},(SPEED*.5)*(float)iterator+(360/(RAYS/4))+(360/(RAYS/2))*i,(Color){255, 236, 80, 2});
    }
    EndBlendMode();
}
