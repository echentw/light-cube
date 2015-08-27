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

void snake(int length) {
  int seq_length = 28;
  int seq[][2] = {{0,  0}, {0,  1}, {0,  2}, {0,  3},
                  {1,  3}, {2,  3}, {2,  7}, {2, 11},
                  {2, 10}, {2,  9}, {2,  8}, {2, 12},
                  {1, 12}, {0, 12}, {0, 13}, {0, 14},
                  {0, 15}, {1, 15}, {2, 15}, {3, 15},
                  {3, 11}, {3,  7}, {3,  3}, {3,  2},
                  {3,  1}, {3,  0}, {2,  0}, {1,  0}};
  for (int i = 0; i < seq_length; ++i) {
    allLightsOff();
    for (int j = 0; j < length; ++j) {
      int layer = seq[(i + j) % seq_length][0];
      int id = seq[(i + j) % seq_length][1];
      lights[layer][id] = HIGH;
    }
    lightUp(lights, 100);
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

