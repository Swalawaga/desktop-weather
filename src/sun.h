#pragma once
#include <iostream>
#include <raylib.h>

#define FLARES 70

class Sun {
    public:
        Sun() ;
        void draw(int iterator) ;
        struct Flare{
            Vector2 pos;
            int size;
            unsigned char alpha;
        };
        Flare flares[FLARES];
    private:
        float x, y;
        
};
