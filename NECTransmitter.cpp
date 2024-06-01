#include "Arduino.h"
#include "NECTransmitter.h"

NECTransmitter::NECTransmitter(byte pin) {
  _pin = pin;
}
void NECTransmitter::begin() {
  pinMode(_pin, OUTPUT);
}

void NECTransmitter::transmitMessage(unsigned int message, byte repeat) {
  this->sendHeader();
  for (byte i = 0; i < 32; i++){
    this->sendValue((message & 0x80000000 >> i) >> 31 - i);
  }
  this->sendEndSequence();

  for (byte i = 0; i < repeat; i++) {
    this->sendRepeatSequence();
  }
}

void NECTransmitter::sendValue(byte value) {
  for(byte i = 0; i < 11; i++) {
    this->sendPulse();
  }
  if (value == 0) {
    delayMicroseconds(562.5);
  } else {
    delayMicroseconds(1687.5);
  }
}

void NECTransmitter::sendHeader() {
  for(int i = 0; i < 171; i++) {
    this->sendPulse();
  }
  delayMicroseconds(4500);
}

void NECTransmitter::sendEndSequence() {
  for(byte i = 0; i < 11; i++) {
    this->sendPulse();
  }
}

void NECTransmitter::sendRepeatSequence() {
  delayMicroseconds(40000);
  for (int i = 0; i < 171; i++) {
    this->sendPulse();
  }
  delayMicroseconds(2500);
  this->sendEndSequence();
}

void NECTransmitter::sendPulse() {
    digitalWrite(_pin, HIGH);
    delayMicroseconds(13.15);
    digitalWrite(_pin, LOW);
    delayMicroseconds(13.15);
}
