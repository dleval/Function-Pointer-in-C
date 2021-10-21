 /**
 * @file alarm.h
 * @author David LEVAL (dleval@dle-dev.com)
 * @brief Periodic Alarm module
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
 
//Callback Function signature 
typedef int (*fpCallback)(int);

//Structure for alarm data
typedef struct S_sPeriodicAlarm
{
    time_t period;
    int nbrOfAlarm;
    time_t lastTimeAlarm;
    fpCallback callback;
    void* next_sPeriodicAlarm;
}sPeriodicAlarm;
//Pointer to structure for alarm data
typedef sPeriodicAlarm* psPeriodicAlarm;

void initPerodicAlarm(sPeriodicAlarm *periodicAlarm_ptr, time_t period, fpCallback callback);
int checkPeriodicAlarm(sPeriodicAlarm *periodicAlarm_ptr);
void checkAllPeriodicAlarm(void);
