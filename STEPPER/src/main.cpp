#include <Arduino.h>
#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 2
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor
const int microstep_div = 1;
const int steps_per_rev_actual = stepsPerRevolution * microstep_div;

void setup()
{
    stepper.setMaxSpeed(1000);
    stepper.setAcceleration(500);
}

void loop()
{
    stepper.move(steps_per_rev_actual);
    stepper.runToPosition();
    delay(1000);

    stepper.move(-(steps_per_rev_actual * 1.5));

    while (stepper.distanceToGo() != 0)
    {
        stepper.run();
    }
    delay(1000);
}