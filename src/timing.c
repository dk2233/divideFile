/*
 * =====================================================================================
 *
 *       Filename:  timing.c
 *
 *    Description: function to measure time period of program run 
 *
 *        Version:  1.0
 *        Created:  11.01.2020 15:49:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/* #####   HEADER FILE INCLUDES   ################################################### */
#include "timing.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  MeasureClock
 *  Description:  this function if call first time start to measure time in ns (depends
 *  of CLOCKS_PER_SEC) second time - it shows how many time has passed 
 * =====================================================================================
 */
void MeasureClock(void)
{
    static clock_t timeStart=0U;
    static uint8_t noOfCall=0U;

    if (0U==timeStart)
    {
        timeStart=clock();
    }

    if (0U!= noOfCall)
    {
        printf(" time diff %ld \n 1 s equals %ld \n\n",clock() - timeStart, CLOCKS_PER_SEC);
        timeStart=0U;
    } 
    noOfCall++;

}

