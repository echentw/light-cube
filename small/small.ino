// constants
#define NUM_74hc595s 3                // number of registers
#define NUM_REG_PINS NUM_74hc595s * 8 // number of register pins
#define SIZE 4                        // number of LEDs per edge
#define LAYER_SIZE 16                 // number of LEDs per layer

// pins
int SER_Pin   = 8;   // pin 14 on the 75HC595
int RCLK_Pin  = 9;   // pin 12 on the 75HC595
int SRCLK_Pin = 10;  // pin 11 on the 75HC595

// registers
bool registers[NUM_REG_PINS];   // 0-3 decides which layer to light up
                                // 8-23 decides which column to light up
bool floor0[LAYER_SIZE];
bool floor1[LAYER_SIZE];
bool floor2[LAYER_SIZE];
bool floor3[LAYER_SIZE];

// helper functions
void setup();

/* set all registers to LOW or HIGH */
void clearRegisters();
void fillAllRegisters();

/* pass values from floor1[] thru floor3[] to registers[] */
void writeRegisters();

/* set an individual pin to HIGH or LOW */
void setRegisterPin(int index, int value);

/* set all registers for the layer to LOW */
void clearLayer();

/* light up the cube given each layer configuration */
void lightUp(bool first[], bool second[], bool third[], bool fourth[],
             int repeat);

/* set all floor arrays to either on or off */
void allFloorOff();
void allFloorOn();

/* light up a particular column */
void lightUpCol(int index);

void fillEight(bool floorLoc[], int startPoint);
void fillReverseEight(bool floorLoc[], int startPoint);

/* PATTERNS */
void switchingRows();
void reverseSwitchingRows();
void switchingEmptyRows();
void reverseSwitchingEmptyRows();
void fillingUp();
void rotate(int size);

// TODO: unimplemented patterns
void randomWalk();
void rain();
void plague();
void randomLights();


// MAIN LOOP
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

void setup() {
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  // reset all register pins
  clearRegisters();
  writeRegisters();
}               

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

// Set and display registers
// Only call AFTER all values are set (slow otherwise)
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

// Inputs four arrays that determine the pattern of each floor.
// This will light up each row at a time fast enough that
//   it seems like all rows are litten up
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

// turn of all floor lights
void allFloorOff() {
  for(int i = 0; i < LAYER_SIZE; ++i) {
    floor0[i] = LOW;
    floor1[i] = LOW;
    floor2[i] = LOW;
    floor3[i] = LOW;
  } 
}

// turn on all floor lights
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

// pattern of moving rows
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

// pattern of moving rows the other direction
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

// switching emptry rows
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

// switching emptry rows
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

// pattern of filling up the cube
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
