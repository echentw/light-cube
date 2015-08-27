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

void lightUp(bool lights[][LAYER_SIZE], int repeat) {
  for (int t = 0; t < repeat; ++t) {
    for (int layer = 0; layer < SIZE; ++layer) {
      clearRegisters();
      setRegisterPin(layer, HIGH);
      for (int i = 0; i < LAYER_SIZE; ++i) {
        if (lights[layer][i]) {
          setRegisterPin(i + 8, HIGH);
        } else {
          setRegisterPin(i + 8, LOW);
        }
      }
      writeRegisters();
    }
  }
}

void allLightsOff() {
  for(int i = 0; i < LAYER_SIZE; ++i) {
    lights[0][i] = LOW;
    lights[1][i] = LOW;
    lights[2][i] = LOW;
    lights[3][i] = LOW;
  }
}

void allLightsOn() {
  for (int i = 0; i < LAYER_SIZE; ++i) {
    lights[0][i] = HIGH;
    lights[1][i] = HIGH;
    lights[2][i] = HIGH;
    lights[3][i] = HIGH;
  }
}

void lightUpCol(int index) {
  lights[0][index] = HIGH;
  lights[1][index] = HIGH;
  lights[2][index] = HIGH;
  lights[3][index] = HIGH;
}

void fillEight(bool floorLoc[], int startPoint) {
  floorLoc[startPoint] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 1] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 2] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 3] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 7] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 6] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 5] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 4] = HIGH;
  lightUp(lights, 50);
}

void fillReverseEight(bool floorLoc[], int startPoint) {
  floorLoc[startPoint + 4] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 5] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 6] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 7] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 3] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 2] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint + 1] = HIGH;
  lightUp(lights, 50);
  floorLoc[startPoint] = HIGH;
  lightUp(lights, 50);
}

