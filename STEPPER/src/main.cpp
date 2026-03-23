#include <Arduino.h>
 
const uint8_t DIR_PIN = 8;
const uint8_t STEP_PIN = 7;

const uint16_t STEPS_PER_REV = 200;
const uint8_t MICROSTEPS = 16;
const uint16_t PULSES_PER_REV = STEPS_PER_REV * MICROSTEPS;

const uint16_t STEP_PULSE_US = 500;
const uint16_t STEP_INTERVAL_US = 1500;

void setup()
{
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(STEP_PIN, LOW);
}

void loop()
{
    for (uint16_t i = 0; i < PULSES_PER_REV; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(STEP_PULSE_US);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(STEP_INTERVAL_US);
    }
}