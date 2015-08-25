int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 3 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

// 0-3 decides which floor to light up
// 8-23 decides which column to light up 
boolean registers[numOfRegisterPins];
bool floor0[16];
bool floor1[16];
bool floor2[16];
bool floor3[16];

void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);


  //reset all register pins
  clearRegisters();
  writeRegisters();
}               

  
//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 

// set all register pins to HIGH
void allFilled(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;
  }
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}

int light_id = 0;
void clearLittle(){
  for (int i = 8; i <= 23; i++){
    registers[i] = LOW;
  }
}

// inputs four arrays that determine the pattern of each floor
// this will light up each row at a time fast enough that it seems like all rows are litten up
void lightUp(bool first[], bool second[], bool third[], bool fourth[], int repeat){
  // repeat decides how long the pattern is going to last
  for(int t = 0; t < repeat; t++){
    clearRegisters();
    setRegisterPin(0, HIGH); // turn on first floor
    // go through each column and decide which one to light up
    for(int i = 8; i < 24; i++){
      if (first[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();
  
    clearRegisters();
    setRegisterPin(1, HIGH); // turn on second floor
    for(int i = 8; i < 24; i++){
      if (second[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();
  
    clearRegisters();
    setRegisterPin(2, HIGH); // turn on third floor
    for(int i = 8; i < 24; i++){
      if (third[i - 8]) {
        setRegisterPin(i, HIGH);
      } else {
        setRegisterPin(i, LOW);
      }
    }
    writeRegisters();
  
    clearRegisters();
    setRegisterPin(3, HIGH); // turn on fourth floor
    for(int i = 8; i < 24; i++){
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
void allFloorOff(){
  for(int i = 0; i < 16; i++){
    floor0[i] = LOW;
    floor1[i] = LOW;
    floor2[i] = LOW;
    floor3[i] = LOW;
    
  } 
}

//pattern of moving rows
void switchingRows(){
  for(int i = 0; i < 4; i++){
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
    lightUp(floor0, floor1, floor2, floor3, 200);    
  }
}

void randomWalk(){
}

void Rain(){
}
void loop(){
  switchingRows();  
}
