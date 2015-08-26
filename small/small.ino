int SER_Pin   = 8;   //pin 14 on the 75HC595
int RCLK_Pin  = 9;   //pin 12 on the 75HC595
int SRCLK_Pin = 10;  //pin 11 on the 75HC595

// How many of the shift registers - change this
#define number_of_74hc595s 3 

// do not touch
#define numOfRegisterPins number_of_74hc595s * 8

// 0-3 decides which floor to light up
// 8-23 decides which column to light up 
boolean registers[numOfRegisterPins];
bool floor0[16];
bool floor1[16];
bool floor2[16];
bool floor3[16];

void setup() {
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  // reset all register pins
  clearRegisters();
  writeRegisters();
}               

// set all register pins to LOW
void clearRegisters() {
  for (int i = 0; i < numOfRegisterPins; ++i) {
    registers[i] = LOW;
  }
} 

// set all register pins to HIGH
void allFilled() {
  for (int i = 0; i < numOfRegisterPins; ++i) {
    registers[i] = HIGH;
  }
} 

// Set and display registers
// Only call AFTER all values are set (slow otherwise)
void writeRegisters() {
  digitalWrite(RCLK_Pin, LOW);
  for (int i = numOfRegisterPins - 1; i >= 0; --i) {
    digitalWrite(SRCLK_Pin, LOW);
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  }
  digitalWrite(RCLK_Pin, HIGH);
}

// set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}

void clearLittle() {
  for (int i = 8; i < 24; ++i) {
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
    for (int i = 8; i < 24; ++i) {
      if (first[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();

    clearRegisters();
    setRegisterPin(1, HIGH); // turn on second floor
    for (int i = 8; i < 24; ++i) {
      if (second[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();

    clearRegisters();
    setRegisterPin(2, HIGH); // turn on third floor
    for (int i = 8; i < 24; ++i) {
      if (third[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();
  
    clearRegisters();
    setRegisterPin(3, HIGH); // turn on fourth floor
    for (int i = 8; i < 24; ++i) {
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
  for(int i = 0; i < 16; ++i){
    floor0[i] = LOW;
    floor1[i] = LOW;
    floor2[i] = LOW;
    floor3[i] = LOW;
  } 
}

// turn on all floor lights
void allFloorOn() {
  for (int i = 0; i < 16; ++i) {
    floor0[i] = HIGH;
    floor1[i] = HIGH;
    floor2[i] = HIGH;
    floor3[i] = HIGH;
  }
}

// pattern of moving rows
void switchingRows() {
  for (int i = 0; i < 4; ++i) {
    allFloorOff();

    floor0[(4*i)%16] = HIGH;
    floor0[(4*i+1)%16] = HIGH;
    floor0[(4*i+2)%16] = HIGH;
    floor0[(4*i+3)%16] = HIGH;  

    floor1[(4*i+4)%16] = HIGH;
    floor1[(4*i+5)%16] = HIGH;
    floor1[(4*i+6)%16] = HIGH;
    floor1[(4*i+7)%16] = HIGH;    

    floor2[(4*i+8)%16] = HIGH;
    floor2[(4*i+9)%16] = HIGH;
    floor2[(4*i+10)%16] = HIGH;
    floor2[(4*i+11)%16] = HIGH;    

    floor3[(4*i+12)%16] = HIGH;
    floor3[(4*i+13)%16] = HIGH;
    floor3[(4*i+14)%16] = HIGH;
    floor3[(4*i+15)%16] = HIGH;

    lightUp(floor0, floor1, floor2, floor3, 75);    
  }
}

// pattern of moving rows the other direction
void reverseSwitchingRows() {
  for (int i = 3; i >= 0; --i) {
    allFloorOff();

    floor0[(4*i)%16] = HIGH;
    floor0[(4*i+1)%16] = HIGH;
    floor0[(4*i+2)%16] = HIGH;
    floor0[(4*i+3)%16] = HIGH;  

    floor1[(4*i+4)%16] = HIGH;
    floor1[(4*i+5)%16] = HIGH;
    floor1[(4*i+6)%16] = HIGH;
    floor1[(4*i+7)%16] = HIGH;    

    floor2[(4*i+8)%16] = HIGH;
    floor2[(4*i+9)%16] = HIGH;
    floor2[(4*i+10)%16] = HIGH;
    floor2[(4*i+11)%16] = HIGH;    

    floor3[(4*i+12)%16] = HIGH;
    floor3[(4*i+13)%16] = HIGH;
    floor3[(4*i+14)%16] = HIGH;
    floor3[(4*i+15)%16] = HIGH;

    lightUp(floor0, floor1, floor2, floor3, 75);    
  }
}

// switching emptry rows
void switchingEmptyRows(){
  for (int i = 0; i < 4; ++i) {
    allFloorOn();

    floor0[(4*i)%16] = LOW;
    floor0[(4*i+1)%16] = LOW;
    floor0[(4*i+2)%16] = LOW;
    floor0[(4*i+3)%16] = LOW;  

    floor1[(4*i+4)%16] = LOW;
    floor1[(4*i+5)%16] = LOW;
    floor1[(4*i+6)%16] = LOW;
    floor1[(4*i+7)%16] = LOW;    

    floor2[(4*i+8)%16] = LOW;
    floor2[(4*i+9)%16] = LOW;
    floor2[(4*i+10)%16] = LOW;
    floor2[(4*i+11)%16] = LOW;    

    floor3[(4*i+12)%16] = LOW;
    floor3[(4*i+13)%16] = LOW;
    floor3[(4*i+14)%16] = LOW;
    floor3[(4*i+15)%16] = LOW;

    lightUp(floor0, floor1, floor2, floor3, 75);    
  }
}

// switching emptry rows
void reverseSwitchingEmptyRows(){
  for (int i = 3; i >= 0; --i) {
    allFloorOn();

    floor0[(4*i)%16] = LOW;
    floor0[(4*i+1)%16] = LOW;
    floor0[(4*i+2)%16] = LOW;
    floor0[(4*i+3)%16] = LOW;  

    floor1[(4*i+4)%16] = LOW;
    floor1[(4*i+5)%16] = LOW;
    floor1[(4*i+6)%16] = LOW;
    floor1[(4*i+7)%16] = LOW;    

    floor2[(4*i+8)%16] = LOW;
    floor2[(4*i+9)%16] = LOW;
    floor2[(4*i+10)%16] = LOW;
    floor2[(4*i+11)%16] = LOW;    

    floor3[(4*i+12)%16] = LOW;
    floor3[(4*i+13)%16] = LOW;
    floor3[(4*i+14)%16] = LOW;
    floor3[(4*i+15)%16] = LOW;

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
  floorLoc[startPoint+1] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+2] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+3] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+7] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+6] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+5] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+4] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
}

void fillReverseEight(bool floorLoc[], int startPoint) {
  floorLoc[startPoint+4] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+5] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+6] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+7] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+3] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+2] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint+1] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
  floorLoc[startPoint] = HIGH;
  lightUp(floor0, floor1, floor2, floor3, 50);
} 

// pattern for random flashing
void randomWalk() {
  // TODO: implement me!
}

void Rain() {
  // TODO: implement me!
}

// infectious pattern
void plague() {
  // TODO: implement me!
}

void randomLights(){
  // TODO: implement me!
}

void loop(){
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
