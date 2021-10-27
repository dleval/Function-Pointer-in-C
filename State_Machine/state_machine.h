#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D,
    NUM_STATES
}t_state;

typedef struct {
    t_state state;
    void (*func)(void);
}t_stateMachine;

void stateAfunc(void);
void stateBfunc(void);
void stateCfunc(void);
void stateDfunc(void);

void stateMachineRun(void);
void setNextState(t_state nextState);

#endif
