/*
  RotaryEncoder - Easily respond to rotary encoder events.
  Created by Robert Reed, August 09, 2022.
  Released into the public domain.
*/

#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Arduino.h"
#include "ec11.h"

typedef void (*eventHandler) (EC11Event::Type);

class RotaryEncoder
{
  public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB);
    RotaryEncoder(uint8_t pinA, uint8_t pinB, bool useInterrupts);

    void begin(eventHandler fn);
    void update();
    void read();
  private:
    EC11 _encoder;
    uint8_t _pinA;
    uint8_t _pinB;
    bool _useInterrupts;
    eventHandler _eventHandler;

    void _setup(uint8_t pinA, uint8_t pinB, bool useInterrupts);
};

#endif
