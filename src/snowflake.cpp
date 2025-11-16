#include <iostream>
#include <raylib.h>

int random2(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}
Flake::Flake() {

}
class Flake {
private:
  double x, y, amplitude, period;
  int size;
public:
  static int iterator = 0;
  Flake() {
    x = random2(0,GetScreenWidth());
    y = random2(0,GetScreenHeight());
    amplitude = random2(-1, 1);
    periods = random2(1, 5);
    size = random2(3,5)
  }
  void draw() {
    DrawRectangle(x, y, size, size, RAYWHITE);
    y += abs(amplitude) * 0.4 + random2(0,1);
    if(y > GetScreenHeight()) {
      y = 0;
    }
    x += amplitude * 0.4 * sin(1/periods * (iterator / 10000.));
    x += amplitude * 0.4 * cos((1/periods*100) * (iterator / 10000.));
    iterator ++;
  }
}
