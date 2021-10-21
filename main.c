 /**
 * @file main.c
 * @author David LEVAL (dleval@dle-dev.com)
 * @brief Main program of Periodic Alarm module example
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

#include "alarm.h"


sPeriodicAlarm firstAlarm;
sPeriodicAlarm secondAlarm;

int firstAlarmCallback(int cnt)
{
    printf("First Alarm callback: %d\n\r", cnt);
    return 0;
}

int secondAlarmCallback(int cnt)
{
    printf("Second Alarm callback: %d\n\r", cnt);
    return 0;
}


int main() 
{
    initPerodicAlarm(&firstAlarm, 2000, &firstAlarmCallback);
    initPerodicAlarm(&secondAlarm, 10000, &secondAlarmCallback);
	
    while(1)
    {
        //checkPeriodicAlarm(&firstAlarm);
        //checkPeriodicAlarm(&secondAlarm);
        checkAllPeriodicAlarm();
        Sleep(10); //Limit usage of CPU
	}
    
    return 0;
}
