#include <iostream>
#include <raylib.h>
#include <math.h>
#include <raymath.h>
#include "sun.h"

#define SIZE 1000
#define RAYS 100
#define SPEED .05

#define SUGMA


Sun::Sun() {
//   x = GetRandomValue(0,GetScreenWidth());
  x = 0;
  y = -20;
  for (int i = 0; i < FLARES; i ++){
    flares[i].pos = (Vector2){x,y} - Vector2Normalize((Vector2){x-GetScreenWidth()/2,y-GetScreenHeight()/2})*(sqrt(pow((GetScreenWidth()/2-x)*2,2)+pow(GetScreenHeight(),2))/FLARES)*i;
    flares[i].alpha = GetRandomValue(0,10);
    if(GetRandomValue(0,5)!=0)
        flares[i].size = GetRandomValue(SIZE/300,SIZE/100);
    else
        flares[i].size = GetRandomValue(SIZE/20,SIZE/7);
  }
}

void Sun::draw(int iterator) {
  x ++;
  if(x > GetScreenWidth()+20) {
    x = -10;
  }
    BeginBlendMode(BLEND_ADDITIVE);
    DrawCircleGradient(x,y,SIZE,(Color){255, 236, 80, 255},BLANK);
    DrawCircleGradient(x,y,SIZE*1.3,(Color){255, 236, 80, 200},BLANK);
    for(int i = 0; i < RAYS/2; i ++){
        DrawRectanglePro((Rectangle){x,y,10000,SIZE/10},(Vector2){0,0},SPEED*(float)iterator+(360/(RAYS/2))*i,(Color){255, 236, 80, 2});
    }
    for(int i = 0; i < RAYS/2; i ++){
        DrawRectanglePro((Rectangle){x,y,10000,SIZE/10},(Vector2){0,0},(SPEED*.5)*(float)iterator+(360/(RAYS/4))+(360/(RAYS/2))*i,(Color){255, 236, 80, 2});
    }
    for(int i = 0 ; i < FLARES; i ++){
        //DrawPoly(flares[i].pos,7,flares[i].size,25,(Color){255, 236, 80, 20});
        flares[i].pos = (Vector2){x,y} - Vector2Normalize((Vector2){x-GetScreenWidth()/2,y-GetScreenHeight()/2})*(sqrt(pow((GetScreenWidth()/2-x)*2,2)+pow(GetScreenHeight(),2))/FLARES)*i;
        DrawCircleV(flares[i].pos,flares[i].size,(Color){255, 236, 80, flares[i].alpha});
    }
    EndBlendMode();
}
