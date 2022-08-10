/*
  RotaryEncoder - Easily respond to rotary encoder events.
  Created by Robert Reed, August 09, 2022.
  Released into the public domain.
*/

/*
Encoder Setup ----------------------------------------------------------------

Connect each pin of the encoder to one of the digital pins on the Arduino. Connect the common pin to ground. If you are going to use an external interrupt, make sure the pin you choose supports that (2 and 3 on arduino boards).
*/

#include <Arduino.h>
#include <RotaryEncoder.h>

const uint8_t pinA = 2;
const uint8_t pinB = 3;

RotaryEncoder encoder(pinA, pinB);
// or 
// const bool useInterrupts = true;
// RotaryEncoder encoder(pinA, pinB, useInterrupts);

// define a callback to handle the encoder evensr
void handleEvent(EC11Event::Type eventType) {
  Serial.println(eventType == EC11Event::StepCW ? "CW" : "CCW");
}

void setup() {
  Serial.begin(115200);

  // handleEvent will be called any time the encoder is rotated
  encoder.begin(handleEvent);
}

void loop() {
  // must call in loop to keep checking the button state
  encoder.update();
}
