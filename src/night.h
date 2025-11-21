#pragma once
#include <iostream>
#include <raylib.h>

class Moon {
    public:
        Moon() ;
        void draw(int iterator) ;
    private:
  float x, y;
  Shader bloom;
        
};
