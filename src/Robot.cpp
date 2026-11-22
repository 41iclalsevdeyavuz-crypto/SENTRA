#include <iostream>
#include "Robot.h"

using namespace std;

Robot::Robot()
    : motorController(10, 5, 90), map(5) {
}

void Robot::runSimulation() {
    cout << "SENTRA V1 Terminal Simulation Started" << endl;

    map.printMap();

    // Scenario 1: front is clear
    distanceSensor.setDistances(50, 0, 0);
    runOneCycle();

    // Scenario 2: front blocked, left is better
    distanceSensor.setDistances(15, 60, 20);
    runOneCycle();

    // Scenario 3: front blocked, right is better
    distanceSensor.setDistances(10, 20, 70);
    runOneCycle();

    // Scenario 4: all sides blocked
    distanceSensor.setDistances(10, 15, 15);
    runOneCycle();

    // Scenario 5: force map expansion
    for (int i = 0; i < 8; i++) {
        distanceSensor.setDistances(80, 0, 0);
        runOneCycle();
    }

    cout << "SENTRA V1 Terminal Simulation Finished" << endl;
}

void Robot::runOneCycle() {
    stateMachine.update(
        distanceSensor.getForwardDistance(),
        distanceSensor.getLeftDistance(),
        distanceSensor.getRightDistance(),
        false,
        false,
        false
    );

    cout << "Current State: "
         << stateToString(stateMachine.getCurrentState()) << endl;

    State currentState = stateMachine.getCurrentState();

    if (currentState == MOVE_FORWARD_STEP) {
        bool completed = motorController.moveForward();
        map.moveRobot(1, 0);

        stateMachine.update(
            distanceSensor.getForwardDistance(),
            distanceSensor.getLeftDistance(),
            distanceSensor.getRightDistance(),
            completed,
            false,
            false
        );
    }
    else if (currentState == TURN_LEFT) {
        bool completed = motorController.turnLeft();

        stateMachine.update(
            distanceSensor.getForwardDistance(),
            distanceSensor.getLeftDistance(),
            distanceSensor.getRightDistance(),
            false,
            completed,
            false
        );
    }
    else if (currentState == TURN_RIGHT) {
        bool completed = motorController.turnRight();

        stateMachine.update(
            distanceSensor.getForwardDistance(),
            distanceSensor.getLeftDistance(),
            distanceSensor.getRightDistance(),
            false,
            completed,
            false
        );
    }
    else if (currentState == MOVE_BACKWARD_STEP) {
        bool completed = motorController.moveBackward();
        map.moveRobot(-1, 0);

        stateMachine.update(
            distanceSensor.getForwardDistance(),
            distanceSensor.getLeftDistance(),
            distanceSensor.getRightDistance(),
            false,
            false,
            completed
        );
    }

    if (stateMachine.getCurrentState() == UPDATE_MAP) {
        stateMachine.update(
            distanceSensor.getForwardDistance(),
            distanceSensor.getLeftDistance(),
            distanceSensor.getRightDistance(),
            false,
            false,
            false
        );
    }

    cout << "Next State: "
         << stateToString(stateMachine.getCurrentState()) << endl;

    map.printMap();
}
