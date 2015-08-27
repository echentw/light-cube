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
    for (int layer = 0; layer < SIZE; ++layer) {
      for (int j = 0; j < SIZE; ++j) {
        lights[layer][(SIZE * (i + layer) + j) % LAYER_SIZE] = HIGH;
      }
    }
    lightUp(lights, 75);
  }
}

void reverseSwitchingRows() {
  for (int i = SIZE - 1; i >= 0; --i) {
    allLightsOff();
    for (int layer = 0; layer < SIZE; ++layer) {
      for (int j = 0; j < SIZE; ++j) {
        lights[layer][(SIZE * (i + layer) + j) % LAYER_SIZE] = HIGH;
      }
    }
    lightUp(lights, 75);
  }
}

void switchingEmptyRows(){
  for (int i = 0; i < SIZE; ++i) {
    allLightsOn();
    for (int layer = 0; layer < SIZE; ++layer) {
      for (int j = 0; j < SIZE; ++j) {
        lights[layer][(SIZE * (i + layer) + j) % LAYER_SIZE] = LOW;
      }
    }
    lightUp(lights, 75);
  }
}

void reverseSwitchingEmptyRows(){
  for (int i = SIZE - 1; i >= 0; --i) {
    allLightsOn();
    for (int layer = 0; layer < SIZE; ++layer) {
      for (int j = 0; j < SIZE; ++j) {
        lights[layer][(SIZE * (i + layer) + j) % LAYER_SIZE] = LOW;
      }
    }
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

