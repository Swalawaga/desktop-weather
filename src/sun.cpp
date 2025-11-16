#include <iostream>
#include <raylib.h>
#include <math.h>
#include "sun.h"

#define SIZE 1000

Sun::Sun() {
  x = random2(0,GetScreenWidth());
  y = 0;
}

void Sun::draw(int iterator) {
  DrawCircleGradient(x,y,SIZE,(Color){255,244,153,255},BLANK);
}

int Sun::random2(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

