
#include<iostream>
#include<vector>
#include "StateMachine.h"
#include "DistanceSensor.h"
#include "MotorController.h"
#include "OccupancyGridMap.h"
#include "Robot.h"
using namespace std;

int main() {
    Robot robot;
    robot.runSimulation();

    return 0;
}
