#include "helper.h"
#include "patterns.h"

void setup() {
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  // reset all register pins
  clearRegisters();
  writeRegisters();
}               

void loop() {
  for (int i = 1; i < 16; ++i) {
    randomLights(i);
  }
  for (int i = 14; i > 0; --i) {
    randomLights(i);
  }

  rotate(1);
  rotate(2);
  rotate(3);
  rotate(2);
  rotate(1);

  fillingUp();

  for (int i = 0; i < 4; ++i) {
    switchingRows();
  }
  for (int i = 0; i < 4; ++i) {
    reverseSwitchingRows();
  }

  fillingUp();

  for (int i = 0; i < 3; ++i) {
    switchingEmptyRows();
  }

  for (int i = 0; i < 3; ++i) {
    reverseSwitchingEmptyRows();
  }

  for (int i = 0; i < 2; ++i) {
    snake(6);
  }
}

