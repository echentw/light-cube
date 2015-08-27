#include "helper.h"

void clearRegisters() {
  for (int i = 0; i < NUM_REG_PINS; ++i) {
    registers[i] = LOW;
  }
}

void fillAllRegisters() {
  for (int i = 0; i < NUM_REG_PINS; ++i) {
    registers[i] = HIGH;
  }
}

void writeRegisters() {
  digitalWrite(RCLK_Pin, LOW);
  for (int i = NUM_REG_PINS - 1; i >= 0; --i) {
    digitalWrite(SRCLK_Pin, LOW);
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  }
  digitalWrite(RCLK_Pin, HIGH);
}

void setRegisterPin(int index, int value) {
  registers[index] = value;
}

void clearLayer() {
  for (int i = 8; i < NUM_REG_PINS; ++i) {
    registers[i] = LOW;
  }
}

void lightUp(bool first[], bool second[], bool third[], bool fourth[],
             int repeat) {
  // repeat decides how long the pattern is going to last
  for (int t = 0; t < repeat; ++t) {
    clearRegisters();
    setRegisterPin(0, HIGH); // turn on first floor
    // go through each column and decide which one to light up
    for (int i = 8; i < NUM_REG_PINS; ++i) {
      if (first[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();

    clearRegisters();
    setRegisterPin(1, HIGH); // turn on second floor
    for (int i = 8; i < NUM_REG_PINS; ++i) {
      if (second[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();

    clearRegisters();
    setRegisterPin(2, HIGH); // turn on third floor
    for (int i = 8; i < NUM_REG_PINS; ++i) {
      if (third[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();

    clearRegisters();
    setRegisterPin(3, HIGH); // turn on fourth floor
    for (int i = 8; i < NUM_REG_PINS; ++i) {
      if (fourth[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();
  }
}

void allFloorOff() {
  for(int i = 0; i < LAYER_SIZE; ++i) {
    floor0[i] = LOW;
    floor1[i] = LOW;
    floor2[i] = LOW;
    floor3[i] = LOW;
  }
}

void allFloorOn() {
  for (int i = 0; i < LAYER_SIZE; ++i) {
    floor0[i] = HIGH;
    floor1[i] = HIGH;
    floor2[i] = HIGH;
    floor3[i] = HIGH;
  }
}

void lightUpCol(int index) {
  floor0[index] = HIGH;
  floor1[index] = HIGH;
  floor2[index] = HIGH;
  floor3[index] = HIGH;
}

void fillEight(bool floorLoc[], int startPoint) {
  floorLoc[startPoint] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 1] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 2] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 3] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 7] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 6] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 5] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 4] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
}

void fillReverseEight(bool floorLoc[], int startPoint) {
  floorLoc[startPoint + 4] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 5] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 6] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 7] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 3] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 2] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint + 1] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
}

