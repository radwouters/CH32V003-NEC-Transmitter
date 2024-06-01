/**
  Send NEC-encoded signals via IR
  Created by Rick Wouters<rick@happytechnology.nl>
  License: GPLv3
**/

#ifndef NECTransmitter_h
#define NECTransmitter_h
#include "Arduino.h";
class NECTransmitter {
  public:
    NECTransmitter(byte pin);
    void transmitMessage(unsigned int message, byte repeat = 0);
    void begin();
  private:
    byte _pin;
    void sendHeader();
    void sendEndSequence();
    void sendValue(byte value);
    void sendRepeatSequence();
    void sendPulse();
};
#endif