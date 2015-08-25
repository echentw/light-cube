int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 3 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);


  //reset all register pins
  clearRegisters();
  writeRegisters();
  for (int i = 0; i < 24; i++){
    setRegisterPin(i, HIGH);
  }
}               

  
//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 

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

void lightUp(bool first[], bool second[], bool third[], bool fourth[], bool repeat){
  clearRegisters();
  setRegisterPin(0, HIGH);
  for(int i = 8; i < 24; i++){
    if (first[i - 8]) {
      setRegisterPin(i, HIGH);
    } else {
      setRegisterPin(i, LOW);
    }
  }
  writeRegisters();

  clearRegisters();
  setRegisterPin(1, HIGH);
  for(int i = 8; i < 24; i++){
    if (second[i - 8]) {
      setRegisterPin(i, HIGH);
    } else {
      setRegisterPin(i, LOW);
    }
  }
  writeRegisters();

  clearRegisters();
  setRegisterPin(2, HIGH);
  for(int i = 8; i < 24; i++){
    if (third[i - 8]) {
      setRegisterPin(i, HIGH);
    } else {
      setRegisterPin(i, LOW);
    }
  }
  writeRegisters();

  clearRegisters();
  setRegisterPin(3, HIGH);
  for(int i = 8; i < 24; i++){
    if (fourth[i - 8]) {
      setRegisterPin(i, HIGH);
    } else {
      setRegisterPin(i, LOW);
    }
  }
  writeRegisters();

  
}
void loop(){
   for (int i = 0; i <=3; i++){
      clearRegisters();
      setRegisterPin(i, HIGH);
      for (int j = 8; j <= 23; j++){
        clearLittle();
        setRegisterPin(j, HIGH);
        writeRegisters();
        for (int k = 1; k<=20; k++){
          clearRegisters();
          writeRegisters();
          delay(3);
          setRegisterPin(i,HIGH);
          setRegisterPin(j, HIGH);
          if (j ==8){
//            setRegisterPin(22, HIGH);
            setRegisterPin(23, HIGH);
          }
          else if (j==9){
//            setRegisterPin(23, HIGH);
            setRegisterPin(8, HIGH);
          }
          else{
//            setRegisterPin(j-2, HIGH);
            setRegisterPin(j-1, HIGH);
          }
          writeRegisters();
          delay(1);
        }
      }
   }
   
   //setRegisterPin(1, HIGH);
   //setRegisterPin(8,HIGH);
   //setRegisterPin(9,HIGH);
   //writeRegisters();   

}
