#ifndef __HELPER__H
#define __HELPER__H

#define NUM_74hc595s 3                // number of registers
#define NUM_REG_PINS NUM_74hc595s * 8 // number of register pins
#define SIZE 4                        // number of LEDs per edge
#define LAYER_SIZE 16                 // number of LEDs per layer

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

/* set all registers to LOW or HIGH */
void clearRegisters();
void fillAllRegisters();

/* pass values from floor1[] thru floor3[] to registers[] */
void writeRegisters();

/* set an individual pin to HIGH or LOW */
void setRegisterPin(int index, int value);

/* set all registers for the layer to LOW */
void clearLayer();

/*
 * light up the cube given each layer configuration
 * Lights up each layer one at a time, fast enough for it to look like
 *   all layers are litten up at the same time.
 */
void lightUp(bool first[], bool second[], bool third[], bool fourth[],
             int repeat);

/* set all floor arrays to either on or off */
void allFloorOff();
void allFloorOn();

/* light up a particular column */
void lightUpCol(int index);

void fillEight(bool floorLoc[], int startPoint);
void fillReverseEight(bool floorLoc[], int startPoint);

#endif

