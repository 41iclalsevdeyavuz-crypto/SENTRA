#ifndef ROBOT_H
#define ROBOT_H

#include "StateMachine.h"
#include "DistanceSensor.h"
#include "MotorController.h"
#include "OccupancyGridMap.h"

class Robot {
private:
    StateMachine stateMachine;
    DistanceSensor distanceSensor;
    MotorController motorController;
    OccupancyGridMap map;

public:
    Robot();

    void runSimulation();
    void runOneCycle();
};

#endif

