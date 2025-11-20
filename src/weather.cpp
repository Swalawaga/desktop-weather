#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include "snowflake.h"
#include "raindrop.h"
#include "sun.h"

using namespace std;

#define SNOWFLAKE_COUNT 600
#define RAINDROP_COUNT 600
#define MAX_AMPLITUDE 100
#define MIN_AMPLITUDE 50

int main() {

  SetConfigFlags(FLAG_WINDOW_TRANSPARENT); 
  InitWindow(GetScreenWidth(), GetScreenHeight(), "Snow Land!");
  SetWindowState(FLAG_WINDOW_UNDECORATED);
  SetWindowState(FLAG_WINDOW_TOPMOST); 
  SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
  SetTargetFPS(60);

  int weather = 0; //0=snowy 1=sunny 2=rain
  int iterator = 0;

  int windSpeed = 0;

  Flake flakes[SNOWFLAKE_COUNT];
  Drop rain[RAINDROP_COUNT];
  Sun sun = Sun();

  for(int i = 0; i < SNOWFLAKE_COUNT;i++) {
    flakes[i] = Flake();
  }

  for(int i = 0; i < RAINDROP_COUNT; i++) {
    rain[i] = Drop();
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLANK);

    switch(weather){
      case 0:
        for(int i = 0; i < SNOWFLAKE_COUNT;i++) {
          flakes[i].draw(iterator, windSpeed);
        }
        break;
      case 1:
        sun.draw(iterator);
        break;
    case 2:
      for(int i = 0; i < RAINDROP_COUNT;i++) {
        rain[i].draw(iterator, windSpeed);
      }
      break;
    }

    iterator++;

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
