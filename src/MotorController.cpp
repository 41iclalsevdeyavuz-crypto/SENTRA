#include <iostream>
#include "MotorController.h"
using namespace std;

MotorController::MotorController(int forwardStepCm, int backwardStepCm, int turnAngle) {
    this->forwardStepCm = forwardStepCm;
    this->backwardStepCm = backwardStepCm;
    this->turnAngleDegrees = turnAngle;
}

bool MotorController::moveForward() {
    cout << "Moving forward " << forwardStepCm << " cm." << endl;
    return true;
}

bool MotorController::moveBackward() {
    cout << "Moving backward " << backwardStepCm << " cm." << endl;
    return true;
}

bool MotorController::turnLeft() {
    cout << "Turning left " << turnAngleDegrees << " degrees." << endl;
    return true;
}

bool MotorController::turnRight() {
    cout << "Turning right " << turnAngleDegrees << " degrees." << endl;
    return true;
}

void MotorController::stop() {
    cout << "Stopping motors." << endl;
}