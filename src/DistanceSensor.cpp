#include "DistanceSensor.h"

DistanceSensor::DistanceSensor() {
    forwardDistance = 0;
    leftDistance = 0;
    rightDistance = 0;
}

void DistanceSensor::setDistances(int forward, int left, int right) {
    forwardDistance = forward;
    leftDistance = left;
    rightDistance = right;
}

int DistanceSensor::getForwardDistance() {
    return forwardDistance;
}

int DistanceSensor::getLeftDistance() {
    return leftDistance;
}

int DistanceSensor::getRightDistance() {
    return rightDistance;
}
