#include "patterns.h"

void rotate(int size) {
  int length = 12; 
  int sequence[] = {0, 1, 2, 3, 7, 11, 15, 14, 13, 12, 8, 4}; 
  for (int i = 0; i < length; ++i) {
    allFloorOff();
    for (int j = 0; j < size; ++j) {
      lightUpCol(sequence[(i + j) % length]);
      lightUpCol(LAYER_SIZE - 1 - sequence[(i + j) % length]);
    }   
    lightUp(floor0, floor1, floor2, floor3, 75);
  }
}

void switchingRows() {
  for (int i = 0; i < SIZE; ++i) {
    allFloorOff();

    floor0[(SIZE * i) % LAYER_SIZE] = HIGH;
    floor0[(SIZE * i + 1) % LAYER_SIZE] = HIGH;
    floor0[(SIZE * i + 2) % LAYER_SIZE] = HIGH;
    floor0[(SIZE * i + 3) % LAYER_SIZE] = HIGH;

    floor1[(SIZE * i + 4) % LAYER_SIZE] = HIGH;
    floor1[(SIZE * i + 5) % LAYER_SIZE] = HIGH;
    floor1[(SIZE * i + 6) % LAYER_SIZE] = HIGH;
    floor1[(SIZE * i + 7) % LAYER_SIZE] = HIGH;

    floor2[(SIZE * i + 8) % LAYER_SIZE] = HIGH;
    floor2[(SIZE * i + 9) % LAYER_SIZE] = HIGH;
    floor2[(SIZE * i + 10) % LAYER_SIZE] = HIGH;
    floor2[(SIZE * i + 11) % LAYER_SIZE] = HIGH;

    floor3[(SIZE * i + 12) % LAYER_SIZE] = HIGH;
    floor3[(SIZE * i + 13) % LAYER_SIZE] = HIGH;
    floor3[(SIZE * i + 14) % LAYER_SIZE] = HIGH;
    floor3[(SIZE * i + 15) % LAYER_SIZE] = HIGH;

    lightUp(floor0, floor1, floor2, floor3, 75);
  }
}

void reverseSwitchingRows() {
  for (int i = SIZE - 1; i >= 0; --i) {
    allFloorOff();

    floor0[(SIZE * i) % LAYER_SIZE] = HIGH;
    floor0[(SIZE * i + 1) % LAYER_SIZE] = HIGH;
    floor0[(SIZE * i + 2) % LAYER_SIZE] = HIGH;
    floor0[(SIZE * i + 3) % LAYER_SIZE] = HIGH;

    floor1[(SIZE * i + 4) % LAYER_SIZE] = HIGH;
    floor1[(SIZE * i + 5) % LAYER_SIZE] = HIGH;
    floor1[(SIZE * i + 6) % LAYER_SIZE] = HIGH;
    floor1[(SIZE * i + 7) % LAYER_SIZE] = HIGH;

    floor2[(SIZE * i + 8) % LAYER_SIZE] = HIGH;
    floor2[(SIZE * i + 9) % LAYER_SIZE] = HIGH;
    floor2[(SIZE * i + 10) % LAYER_SIZE] = HIGH;
    floor2[(SIZE * i + 11) % LAYER_SIZE] = HIGH;

    floor3[(SIZE * i + 12) % LAYER_SIZE] = HIGH;
    floor3[(SIZE * i + 13) % LAYER_SIZE] = HIGH;
    floor3[(SIZE * i + 14) % LAYER_SIZE] = HIGH;
    floor3[(SIZE * i + 15) % LAYER_SIZE] = HIGH;

    lightUp(floor0, floor1, floor2, floor3, 75);
  }
}

void switchingEmptyRows(){
  for (int i = 0; i < SIZE; ++i) {
    allFloorOn();

    floor0[(SIZE * i) % LAYER_SIZE] = LOW;
    floor0[(SIZE * i + 1) % LAYER_SIZE] = LOW;
    floor0[(SIZE * i + 2) % LAYER_SIZE] = LOW;
    floor0[(SIZE * i + 3) % LAYER_SIZE] = LOW;

    floor1[(SIZE * i + 4) % LAYER_SIZE] = LOW;
    floor1[(SIZE * i + 5) % LAYER_SIZE] = LOW;
    floor1[(SIZE * i + 6) % LAYER_SIZE] = LOW;
    floor1[(SIZE * i + 7) % LAYER_SIZE] = LOW;

    floor2[(SIZE * i + 8) % LAYER_SIZE] = LOW;
    floor2[(SIZE * i + 9) % LAYER_SIZE] = LOW;
    floor2[(SIZE * i + 10) % LAYER_SIZE] = LOW;
    floor2[(SIZE * i + 11) % LAYER_SIZE] = LOW;

    floor3[(SIZE * i + 12) % LAYER_SIZE] = LOW;
    floor3[(SIZE * i + 13) % LAYER_SIZE] = LOW;
    floor3[(SIZE * i + 14) % LAYER_SIZE] = LOW;
    floor3[(SIZE * i + 15) % LAYER_SIZE] = LOW;

    lightUp(floor0, floor1, floor2, floor3, 75);
  }
}

void reverseSwitchingEmptyRows(){
  for (int i = SIZE - 1; i >= 0; --i) {
    allFloorOn();

    floor0[(SIZE * i) % LAYER_SIZE] = LOW;
    floor0[(SIZE * i + 1) % LAYER_SIZE] = LOW;
    floor0[(SIZE * i + 2) % LAYER_SIZE] = LOW;
    floor0[(SIZE * i + 3) % LAYER_SIZE] = LOW;

    floor1[(SIZE * i + 4) % LAYER_SIZE] = LOW;
    floor1[(SIZE * i + 5) % LAYER_SIZE] = LOW;
    floor1[(SIZE * i + 6) % LAYER_SIZE] = LOW;
    floor1[(SIZE * i + 7) % LAYER_SIZE] = LOW;

    floor2[(SIZE * i + 8) % LAYER_SIZE] = LOW;
    floor2[(SIZE * i + 9) % LAYER_SIZE] = LOW;
    floor2[(SIZE * i + 10) % LAYER_SIZE] = LOW;
    floor2[(SIZE * i + 11) % LAYER_SIZE] = LOW;

    floor3[(SIZE * i + 12) % LAYER_SIZE] = LOW;
    floor3[(SIZE * i + 13) % LAYER_SIZE] = LOW;
    floor3[(SIZE * i + 14) % LAYER_SIZE] = LOW;
    floor3[(SIZE * i + 15) % LAYER_SIZE] = LOW;

    lightUp(floor0, floor1, floor2, floor3, 75);
  }
}

void fillingUp() {
  allFloorOff();
  fillEight(floor3, 0);
  fillEight(floor3, 8);
  fillReverseEight(floor2, 8);
  fillReverseEight(floor2, 0);
  fillEight(floor1, 0);
  fillEight(floor1, 8);
  fillReverseEight(floor0, 8);
  fillReverseEight(floor0, 0);
}

