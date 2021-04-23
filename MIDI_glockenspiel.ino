/*
 * Larry Bonnette 03/2021
 * fire a solenoid when a certain MIDI note is recieved
 * The solenoid is used to strike a note on a glockenspiel
 */

#include <Wire.h>
#include "Adafruit_MCP23017.h" //MCP23017 - i2c 16 input/output port expander
#include <MIDI.h>  // Add Midi Library
// MCP23017 I/O expander
// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)


#define LED 13    // Arduino Board LED is on Pin 13

void ProgRel(); //Declare so it compiles


//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

int period = 13; // Part of non-blocking delay to turn off solenoid
unsigned long time_now = 0; // Part of non-blocking delay

// Create mcp object for first MCP23017 board
Adafruit_MCP23017 mcp;

// Create mcp1 object for second MCP23017 board
Adafruit_MCP23017 mcp1;
int pinRelease = 99;
int pinRelease1 = 99;
void setup() {
  pinMode (LED, OUTPUT); // Set Arduino board LED pin 13 to output
  
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it 
  // to respond to notes on channel 2 only.
  
  mcp.begin();      // Initialize the MCP23017 library to use default address 0 
  mcp1.begin(1);      // Initialize the second MCP23017 library to use address 21
  
  Serial.begin(115200); // Initialize the serial port to 115200 baud rate. This will be used for MIDI communication
  
  // setting multiple pins as OUTPUT
int outMin = 0; // Lowest output pin
int outMax = 15; // Highest output pin
for(int i=outMin; i<=outMax; i++)
{  
  mcp.pinMode(i, OUTPUT);
  mcp1.pinMode(i,OUTPUT);
}

  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library 
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}

void loop() { // Main loop
  if (millis() >= time_now + period) // Part of non-blocking delay
  {
    time_now = 0;
    ProgRel(); //turns off the solenoid after the non-blocking delay
    }
  
  MIDI.read(); // Continuously check if Midi data has been received.
}

// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  switch (pitch) {
    case 53:
    mcp.digitalWrite(0,HIGH);
    time_now = millis();
    pinRelease = 0;
    break;
    case 54:
    mcp.digitalWrite(1,HIGH);
    time_now = millis();
    pinRelease = 1;
    break;
    case 55:
    mcp.digitalWrite(2,HIGH);
    time_now = millis();
    pinRelease = 2;
    break;
    case 56:
    mcp.digitalWrite(3,HIGH);
    time_now = millis();
    pinRelease = 3;
    break;
    case 57:
    mcp.digitalWrite(4,HIGH);
    time_now = millis();
    pinRelease = 4;
    break;
    case 58:
    mcp.digitalWrite(5,HIGH);
    time_now = millis();
    pinRelease = 5;
    break;
    case 59:
    mcp.digitalWrite(6,HIGH);
    time_now = millis();
    pinRelease = 6;
    break;
    case 60:
    mcp.digitalWrite(7,HIGH);
    time_now = millis();
    pinRelease = 7;
    break;
  case 61:
    mcp.digitalWrite(8,HIGH);
    time_now = millis();
    pinRelease = 8;
    break;
   case 62:
    mcp.digitalWrite(9,HIGH);
    time_now = millis();
    pinRelease = 9;
    break;
   case 63:
    mcp.digitalWrite(10,HIGH);
    time_now = millis();
    pinRelease = 10;
    break;
    case 64:
    mcp.digitalWrite(11,HIGH);
    time_now = millis();
    pinRelease = 11;
    break;
    case 65:
    mcp.digitalWrite(12,HIGH);
    time_now = millis();
    pinRelease = 12;
    break;
    case 66:
    mcp.digitalWrite(13,HIGH);
    time_now = millis();
    pinRelease = 13;
    break;
    case 67:
    mcp.digitalWrite(14,HIGH);
    time_now = millis();
    pinRelease = 14;
    break;
    case 68:
    mcp.digitalWrite(15,HIGH);
    time_now = millis();
    pinRelease = 15;
    break;
    case 69:
    mcp1.digitalWrite(0,HIGH);  //Start accessing the second MCP23017
    time_now = millis();
    pinRelease1 = 0;
    break;
    case 70:
    mcp1.digitalWrite(1,HIGH);
    time_now = millis();
    pinRelease1 = 1;
    break;
    case 71:
    mcp1.digitalWrite(2,HIGH);
    time_now = millis();
    pinRelease1 = 2;
    break;
    case 72:
    mcp1.digitalWrite(3,HIGH);
    time_now = millis();
    pinRelease1 = 3;
    break;
    case 73:
    mcp1.digitalWrite(4,HIGH);
    time_now = millis();
    pinRelease1 = 4;
    break;
    case 74:
    mcp1.digitalWrite(5,HIGH);
    time_now = millis();
    pinRelease1 = 5;
    break;
    case 75:
    mcp1.digitalWrite(6,HIGH);
    time_now = millis();
    pinRelease1 = 6;
    break;
    case 76:
    mcp1.digitalWrite(7,HIGH);
    time_now = millis();
    pinRelease1 = 7;
    break;
    case 77:
    mcp1.digitalWrite(8,HIGH);
    time_now = millis();
    pinRelease1 = 8;
    break;
    case 78:
    mcp1.digitalWrite(9,HIGH);
    time_now = millis();
    pinRelease1 = 9;
    break;
    case 79:
    mcp1.digitalWrite(10,HIGH);
    time_now = millis();
    pinRelease1 = 10;
    break;
    case 80:
    mcp1.digitalWrite(11,HIGH);
    time_now = millis();
    pinRelease1 = 11;
    break;
    case 81:
    mcp1.digitalWrite(12,HIGH);
    time_now = millis();
    pinRelease1 = 12;
    break;
    case 82:
    mcp1.digitalWrite(13,HIGH);
    time_now = millis();
    pinRelease1 = 13;
    break;
    case 83:
    mcp1.digitalWrite(14,HIGH);
    time_now = millis();
    pinRelease1 = 14;
    break;
    case 84:
    mcp1.digitalWrite(15,HIGH);
    time_now = millis();
    pinRelease1 = 15;
    break;
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
} 
  digitalWrite(LED,HIGH);  //Turn LED on
}

// MyHandleNoteOff is the function that will be called by the Midi Library
// when a MIDI NOTE Off message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
// This routine is used to fulfill the note off sent to us. The "ProgRel" routine is the real solenoid release routine
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
/*  if (pinRelease != 99){
  mcp.digitalWrite(pinRelease,LOW);
  pinRelease = 99; 
  }else
  if (pinRelease1 != 99) {
      mcp1.digitalWrite(pinRelease1,LOW);
  pinRelease1 = 99;
  }*/
  digitalWrite(LED,LOW);  //Turn LED off
}

void ProgRel() {
  if (pinRelease != 99){
  mcp.digitalWrite(pinRelease,LOW);
  pinRelease = 99; 
  }else
  if (pinRelease1 != 99) {
      mcp1.digitalWrite(pinRelease1,LOW);
  pinRelease1 = 99;
  }
  digitalWrite(LED,LOW);  //Turn LED off
}
