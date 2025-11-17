#pragma once
#include <iostream>
#include <raylib.h>


class Sun {
    private:
        float x, y;
    public:
        Sun() ;
        void draw(int iterator) ;
        int random2(int min, int max);
};
