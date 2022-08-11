/*
  RotaryEncoder - Easily respond to rotary encoder events.
  Created by Robert Reed, August 09, 2022.
  Released into the public domain.
*/


#include "Arduino.h"
#include "RotaryEncoder.h"

// constructor
RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB)
{
  _setup(pinA, pinB, false);
}

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, bool useInterrupts)
{
  _setup(pinA, pinB, useInterrupts);
}

// Private Members
void RotaryEncoder::_setup(uint8_t pinA, uint8_t pinB, bool useInterrupts)
{
  _pinA = pinA;
  _pinB = pinB;
  _useInterrupts = useInterrupts;
}

// Public Members
void RotaryEncoder::begin(eventHandler fn) {
  if (_eventHandler) return;

  _eventHandler = fn;
  pinMode(_pinA, INPUT_PULLUP);
  pinMode(_pinB, INPUT_PULLUP);
}

void RotaryEncoder::update()
{
  if (!_eventHandler) {
    return;
  }

  if (!_useInterrupts) {
    // read the pins manually since there are no interrupts
    read();
  }

  EC11Event event;
  if (_encoder.read(&event)) {
    _eventHandler(event);
  }
}

void RotaryEncoder::read()
{
  _encoder.checkPins(digitalRead(_pinA), digitalRead(_pinB));
}
