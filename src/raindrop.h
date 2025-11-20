#pragma once
#include <iostream>
#include <raylib.h>


class Drop{
private:
  double x, y, amplitude, period;
  int size;
public:
  Drop() ;
  void draw(int iterator, int slope) ;
  int random2(int min, int max);
};
