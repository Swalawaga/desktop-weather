#include <iostream>
#include <raylib.h>
#include <math.h>
#include "raindrop.h"

Drop::Drop() {
  x = random2(0,GetScreenWidth());
  y = random2(0,GetScreenHeight());
  amplitude = random2(-1, 1);
  period = random2(1, 5);
  size = random2(3,5);
}

void Drop::draw(int iterator, int slope) {
  DrawRectangle(x, y, size, size+5, BLUE);
  y += abs(amplitude) * 0.4 + random2(0,1) + slope * 2;
  if(y > GetScreenHeight()) {
    y = 0;
  }
  x += amplitude * 0.4 * sin(1/period * (iterator / 10000.)) + slope;
  x += amplitude * 0.4 * cos((1/period*100) * (iterator / 10000.));
  if(x > GetScreenWidth()+2) {
    x = -2;
  }
}

int Drop::random2(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}
