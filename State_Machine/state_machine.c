#include <stdio.h>
#include "state_machine.h"

t_state actualState = STATE_A;

t_stateMachine stateMachine[NUM_STATES] = {
    { STATE_A, stateAfunc },
    { STATE_B, stateBfunc },
    { STATE_C, stateCfunc },
    { STATE_D, stateDfunc }
};

void stateMachineRun(void)
{
    if(actualState < NUM_STATES)
    {
    	(*stateMachine[actualState].func)();
    } else {
        //Error
    }
}

void setNextState(t_state nextState)
{
    actualState = nextState;
}

