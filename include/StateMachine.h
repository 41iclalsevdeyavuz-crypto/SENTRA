#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include <string>
//These are called preprocessor directive
//Let's say ı called stateMachine.h in other multıple files
// lets say ınsıde robot.h and ın maın.cpp, and ı aso use robot.h on main
//then the compiler will give an error because ı am actually
//including stateMachine.h twice once directly in main.cpp and once indirectly through robot.h
// so the #ifndef #define and #endif directives are for
// ensuring that the header file is included only once during compilation.
//(basically ifndef -> if not defined, define it)
enum State {
    IDLE,
    SCAN_FRONT,
    MOVE_FORWARD_STEP,
    SCAN_LEFT_RIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    MOVE_BACKWARD_STEP,
    UPDATE_MAP,
    MISSION_COMPLETED
};

std::string stateToString(State state);

class StateMachine {
private:
    State currentState;

public:
    StateMachine();

    void changeState(State newState);

    State getCurrentState();

    void update(int forwardDistance,
                int leftDistance,
                int rightDistance,
                bool stepCompleted,
                bool turnCompleted,
                bool backwardStepCompleted);
};

#endif // and thıs is the end of the preprocessor directive
// for ex: ifndef was defined before, then ıt would skip everythıng until here
