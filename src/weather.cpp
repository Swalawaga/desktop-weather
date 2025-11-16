#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include "snowflake.h"
#include "sun.h"

using namespace std;

#define SNOWFLAKE_COUNT 600
#define MAX_AMPLITUDE 100
#define MIN_AMPLITUDE 50

int main() {

  SetConfigFlags(FLAG_WINDOW_TRANSPARENT); 
  InitWindow(GetScreenWidth(), GetScreenHeight(), "Snow Land!");
  SetWindowState(FLAG_WINDOW_UNDECORATED);
  SetWindowState(FLAG_WINDOW_TOPMOST); 
  SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
  SetTargetFPS(60);

  int weather = 1; //0=snowy 1=sunny
  int iterator = 0;

  Flake flakes[SNOWFLAKE_COUNT];

  Sun sun = Sun();

  for(int i = 0; i < SNOWFLAKE_COUNT;i++) {
    flakes[i] = Flake();
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLANK);

    switch(weather){
      case 0:
        for(int i = 0; i < SNOWFLAKE_COUNT;i++) {
          flakes[i].draw(iterator);
        }
      case 1:
        sun.draw(iterator);
    }

    iterator++;

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
