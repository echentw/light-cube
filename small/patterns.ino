#include "patterns.h"

void rotate(int size) {
  int length = 12; 
  int sequence[] = {0, 1, 2, 3, 7, 11, 15, 14, 13, 12, 8, 4}; 
  for (int i = 0; i < length; ++i) {
    allLightsOff();
    for (int j = 0; j < size; ++j) {
      lightUpCol(sequence[(i + j) % length]);
      lightUpCol(LAYER_SIZE - 1 - sequence[(i + j) % length]);
    }   
    lightUp(lights, 75);
  }
}

void switchingRows() {
  for (int i = 0; i < SIZE; ++i) {
    allLightsOff();

    lights[0][(SIZE * i) % LAYER_SIZE] = HIGH;
    lights[0][(SIZE * i + 1) % LAYER_SIZE] = HIGH;
    lights[0][(SIZE * i + 2) % LAYER_SIZE] = HIGH;
    lights[0][(SIZE * i + 3) % LAYER_SIZE] = HIGH;

    lights[1][(SIZE * i + 4) % LAYER_SIZE] = HIGH;
    lights[1][(SIZE * i + 5) % LAYER_SIZE] = HIGH;
    lights[1][(SIZE * i + 6) % LAYER_SIZE] = HIGH;
    lights[1][(SIZE * i + 7) % LAYER_SIZE] = HIGH;

    lights[2][(SIZE * i + 8) % LAYER_SIZE] = HIGH;
    lights[2][(SIZE * i + 9) % LAYER_SIZE] = HIGH;
    lights[2][(SIZE * i + 10) % LAYER_SIZE] = HIGH;
    lights[2][(SIZE * i + 11) % LAYER_SIZE] = HIGH;

    lights[3][(SIZE * i + 12) % LAYER_SIZE] = HIGH;
    lights[3][(SIZE * i + 13) % LAYER_SIZE] = HIGH;
    lights[3][(SIZE * i + 14) % LAYER_SIZE] = HIGH;
    lights[3][(SIZE * i + 15) % LAYER_SIZE] = HIGH;

    lightUp(lights, 75);
  }
}

void reverseSwitchingRows() {
  for (int i = SIZE - 1; i >= 0; --i) {
    allLightsOff();

    lights[0][(SIZE * i) % LAYER_SIZE] = HIGH;
    lights[0][(SIZE * i + 1) % LAYER_SIZE] = HIGH;
    lights[0][(SIZE * i + 2) % LAYER_SIZE] = HIGH;
    lights[0][(SIZE * i + 3) % LAYER_SIZE] = HIGH;

    lights[1][(SIZE * i + 4) % LAYER_SIZE] = HIGH;
    lights[1][(SIZE * i + 5) % LAYER_SIZE] = HIGH;
    lights[1][(SIZE * i + 6) % LAYER_SIZE] = HIGH;
    lights[1][(SIZE * i + 7) % LAYER_SIZE] = HIGH;

    lights[2][(SIZE * i + 8) % LAYER_SIZE] = HIGH;
    lights[2][(SIZE * i + 9) % LAYER_SIZE] = HIGH;
    lights[2][(SIZE * i + 10) % LAYER_SIZE] = HIGH;
    lights[2][(SIZE * i + 11) % LAYER_SIZE] = HIGH;

    lights[3][(SIZE * i + 12) % LAYER_SIZE] = HIGH;
    lights[3][(SIZE * i + 13) % LAYER_SIZE] = HIGH;
    lights[3][(SIZE * i + 14) % LAYER_SIZE] = HIGH;
    lights[3][(SIZE * i + 15) % LAYER_SIZE] = HIGH;

    lightUp(lights, 75);
  }
}

void switchingEmptyRows(){
  for (int i = 0; i < SIZE; ++i) {
    allLightsOn();

    lights[0][(SIZE * i) % LAYER_SIZE] = LOW;
    lights[0][(SIZE * i + 1) % LAYER_SIZE] = LOW;
    lights[0][(SIZE * i + 2) % LAYER_SIZE] = LOW;
    lights[0][(SIZE * i + 3) % LAYER_SIZE] = LOW;

    lights[1][(SIZE * i + 4) % LAYER_SIZE] = LOW;
    lights[1][(SIZE * i + 5) % LAYER_SIZE] = LOW;
    lights[1][(SIZE * i + 6) % LAYER_SIZE] = LOW;
    lights[1][(SIZE * i + 7) % LAYER_SIZE] = LOW;

    lights[2][(SIZE * i + 8) % LAYER_SIZE] = LOW;
    lights[2][(SIZE * i + 9) % LAYER_SIZE] = LOW;
    lights[2][(SIZE * i + 10) % LAYER_SIZE] = LOW;
    lights[2][(SIZE * i + 11) % LAYER_SIZE] = LOW;

    lights[3][(SIZE * i + 12) % LAYER_SIZE] = LOW;
    lights[3][(SIZE * i + 13) % LAYER_SIZE] = LOW;
    lights[3][(SIZE * i + 14) % LAYER_SIZE] = LOW;
    lights[3][(SIZE * i + 15) % LAYER_SIZE] = LOW;

    lightUp(lights, 75);
  }
}

void reverseSwitchingEmptyRows(){
  for (int i = SIZE - 1; i >= 0; --i) {
    allLightsOn();

    lights[0][(SIZE * i) % LAYER_SIZE] = LOW;
    lights[0][(SIZE * i + 1) % LAYER_SIZE] = LOW;
    lights[0][(SIZE * i + 2) % LAYER_SIZE] = LOW;
    lights[0][(SIZE * i + 3) % LAYER_SIZE] = LOW;

    lights[1][(SIZE * i + 4) % LAYER_SIZE] = LOW;
    lights[1][(SIZE * i + 5) % LAYER_SIZE] = LOW;
    lights[1][(SIZE * i + 6) % LAYER_SIZE] = LOW;
    lights[1][(SIZE * i + 7) % LAYER_SIZE] = LOW;

    lights[2][(SIZE * i + 8) % LAYER_SIZE] = LOW;
    lights[2][(SIZE * i + 9) % LAYER_SIZE] = LOW;
    lights[2][(SIZE * i + 10) % LAYER_SIZE] = LOW;
    lights[2][(SIZE * i + 11) % LAYER_SIZE] = LOW;

    lights[3][(SIZE * i + 12) % LAYER_SIZE] = LOW;
    lights[3][(SIZE * i + 13) % LAYER_SIZE] = LOW;
    lights[3][(SIZE * i + 14) % LAYER_SIZE] = LOW;
    lights[3][(SIZE * i + 15) % LAYER_SIZE] = LOW;

    lightUp(lights, 75);
  }
}

void fillingUp() {
  allLightsOff();
  fillEight(lights[3], 0);
  fillEight(lights[3], 8);
  fillReverseEight(lights[2], 8);
  fillReverseEight(lights[2], 0);
  fillEight(lights[1], 0);
  fillEight(lights[1], 8);
  fillReverseEight(lights[0], 8);
  fillReverseEight(lights[0], 0);
}

