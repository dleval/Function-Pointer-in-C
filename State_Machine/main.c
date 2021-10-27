 /**
 * @file main.c
 * @author David LEVAL (dleval@dle-dev.com)
 * @brief Main program of State Machine example
 * @version 1.0
 * @date 2021-10-06
 * 
 * @copyright Copyright (c) 2021
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <sys/time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) sleep(x)
#endif

#ifdef _WIN32
	#pragma message "OS : Windows"
#elif __linux__
	#pragma message "OS : Linux"
#elif __unix__
	#pragma message "OS : Other unix"
#else
	#pragma message "OS : Unidentified"
#endif

#include "state_machine.h"

void stateAfunc(void)
{
    printf("State A running\n\r");
    setNextState(STATE_B);
}

void stateBfunc(void)
{
    printf("State B running\n\r");
    setNextState(STATE_C);
}

void stateCfunc(void)
{
    printf("State C running\n\r");
    setNextState(STATE_D);
}

void stateDfunc(void)
{
    printf("State D running\n\r");
    setNextState(STATE_A);
}


int main() 
{
    printf("State Machine with function pointer example\n\r");
    for(int i=0; i<6; i++)
    {
        stateMachineRun();
        //Sleep(10); //Limit usage of CPU
    }
    
    return 0;
}
