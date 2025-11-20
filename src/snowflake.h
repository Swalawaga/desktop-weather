#pragma once
#include <iostream>
#include <raylib.h>


class Flake {
    private:
        double x, y, amplitude, period;
        int size;
    public:
        Flake() ;
  void draw(int iterator) ;
        int random2(int min, int max);
};
