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

  switchingRows();
  switchingRows();
  switchingRows();
  switchingRows();

  reverseSwitchingRows();
  reverseSwitchingRows();
  reverseSwitchingRows();
  reverseSwitchingRows();

  fillingUp();

  switchingEmptyRows();
  switchingEmptyRows();
  switchingEmptyRows();

  reverseSwitchingEmptyRows();
  reverseSwitchingEmptyRows();
  reverseSwitchingEmptyRows();

  snake(6);
}

