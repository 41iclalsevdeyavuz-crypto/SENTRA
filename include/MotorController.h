
#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

class MotorController {
private:
    int forwardStepCm;
    int backwardStepCm;
    int turnAngleDegrees;

public:
    MotorController(int forwardStepCm, int backwardStepCm, int turnAngle);

    bool moveForward();
    bool moveBackward();
    bool turnLeft();
    bool turnRight();
    void stop();
};

#endif