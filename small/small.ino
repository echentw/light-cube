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
}


