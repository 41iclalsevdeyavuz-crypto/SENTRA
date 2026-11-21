#include "StateMachine.h"

const int OBSTACLE_THRESHOLD = 30;

std::string stateToString(State state) {
    switch (state) {
        case IDLE: return "IDLE";
        case SCAN_FRONT: return "SCAN_FRONT";
        case MOVE_FORWARD_STEP: return "MOVE_FORWARD_STEP";
        case SCAN_LEFT_RIGHT: return "SCAN_LEFT_RIGHT";
        case TURN_LEFT: return "TURN_LEFT";
        case TURN_RIGHT: return "TURN_RIGHT";
        case MOVE_BACKWARD_STEP: return "MOVE_BACKWARD_STEP";
        case UPDATE_MAP: return "UPDATE_MAP";
        case MISSION_COMPLETED: return "MISSION_COMPLETED";
        default: return "UNKNOWN_STATE";
    }
}

StateMachine::StateMachine(){
    currentState = IDLE;
}

void StateMachine::changeState(State newState){
    currentState = newState;
}

State StateMachine::getCurrentState(){
    return currentState;
}

void StateMachine::update(
    int forwardDistance,
    int leftDistance,
    int rightDistance,
    bool stepCompleted,
    bool turnCompleted,
    bool backwardStepCompleted){

    switch (currentState) {

        case IDLE:
            changeState(SCAN_FRONT);
            break;

        case SCAN_FRONT:
            if(forwardDistance > OBSTACLE_THRESHOLD){
                changeState(MOVE_FORWARD_STEP);
            }
            else{
                changeState(SCAN_LEFT_RIGHT);
            }
            break;

        case MOVE_FORWARD_STEP:
            if(stepCompleted){
                changeState(UPDATE_MAP);
            }
            break;

        case SCAN_LEFT_RIGHT:
            if(leftDistance > OBSTACLE_THRESHOLD &&
               leftDistance > rightDistance){

                changeState(TURN_LEFT);
            }
            else if(rightDistance > OBSTACLE_THRESHOLD &&
                    rightDistance >= leftDistance){

                changeState(TURN_RIGHT);
            }
            else{
                changeState(MOVE_BACKWARD_STEP);
            }
            break;

        case TURN_LEFT:
            if(turnCompleted){
                changeState(SCAN_FRONT);
            }
            break;

        case TURN_RIGHT:
            if(turnCompleted){
                changeState(SCAN_FRONT);
            }
            break;

        case MOVE_BACKWARD_STEP:
            if(backwardStepCompleted){
                changeState(SCAN_FRONT);
            }
            break;

        case UPDATE_MAP:
            changeState(SCAN_FRONT);
            break;

        case MISSION_COMPLETED:
            break;
    }
}