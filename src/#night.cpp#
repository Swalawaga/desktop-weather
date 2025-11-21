#include <iostream>
#include <raylib.h>
#include <math.h>
#include <raymath.h>
#include "night.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#define MAX_POSTPRO_SHADERS         12

Moon::Moon() {
  bloom = LoadShader(0, TextFormat("shaders/bloom.fs", GLSL_VERSION));
  x = 0;
  y = -20;
}

void Moon::draw(int iterator) {
  BeginShaderMode(bloom);
  
  EndShaderMode();
}
