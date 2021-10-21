 /**
 * @file alarm.c
 * @author David LEVAL (dleval@dle-dev.com)
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

#ifdef _WIN32
#include <windows.h>
#include <sys/time.h>
#else
#include <unistd.h>
#include <time.h>
#endif

#include "alarm.h"

volatile psPeriodicAlarm firstPeriodicAlarm_ptr = NULL;
volatile psPeriodicAlarm lastPeriodicAlarm_ptr = NULL;

/**
 * @brief Initialize a periodic alarm with the parameters in arguments
 * 
 * @param periodicAlarm_ptr     Pointer to alarm data structure
 * @param period                Trigger period
 * @param callback              Pointer to callback function
 */
void initPerodicAlarm(sPeriodicAlarm *periodicAlarm_ptr, time_t period, fpCallback callback)
{
    periodicAlarm_ptr->period = period;
    periodicAlarm_ptr->nbrOfAlarm = 0;
    periodicAlarm_ptr->lastTimeAlarm = time(NULL) * 1000;
    periodicAlarm_ptr->callback = callback;
    periodicAlarm_ptr->next_sPeriodicAlarm = NULL;
    
    //Check if is the first alarm
    if(lastPeriodicAlarm_ptr != NULL)
        lastPeriodicAlarm_ptr->next_sPeriodicAlarm = periodicAlarm_ptr;
    else
        firstPeriodicAlarm_ptr = periodicAlarm_ptr;
    
    lastPeriodicAlarm_ptr = periodicAlarm_ptr;
}

/**
 * @brief Check if an alarm is active and execute the associated callback function
 * 
 * @param periodicAlarm_ptr     Pointer to alarm data structure
 * @return int                  Status of callback function
 */
int checkPeriodicAlarm(sPeriodicAlarm *periodicAlarm_ptr)
{
    int ret = -1;
    time_t mnow = time(NULL) * 1000;
    
    if(mnow > (periodicAlarm_ptr->lastTimeAlarm  + periodicAlarm_ptr->period))
    {
        periodicAlarm_ptr->lastTimeAlarm = mnow;
        ++periodicAlarm_ptr->nbrOfAlarm;
        if(periodicAlarm_ptr->callback != NULL)
            ret = periodicAlarm_ptr->callback(periodicAlarm_ptr->nbrOfAlarm);
    }
    
    return ret;
}

/**
 * @brief Checks all the alarms and executes the associated callback functions
 * 
 */
void checkAllPeriodicAlarm(void)
{
    psPeriodicAlarm actualPeriodicAlarm_ptr = firstPeriodicAlarm_ptr;
    
    while(actualPeriodicAlarm_ptr != NULL)
    {
        checkPeriodicAlarm(actualPeriodicAlarm_ptr);
        actualPeriodicAlarm_ptr = actualPeriodicAlarm_ptr->next_sPeriodicAlarm;
    }
}
