/*
 **********************************************************************************************************************
Here we compute statistics for a bunch of numbers.
This project uses the [catch framework](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top)
to test functionality.
The tests are defined in C++, while the code is in C.
 **********************************************************************************************************************
 */
#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

//----------------------------------------------------------------------------
// Brief: Swap fucntion to swap the contents of a variable
// Return: None
//----------------------------------------------------------------------------
void swap(float *configptr0, float *configptr1)
{
    float tempVal = *configptr0;
    *configptr0 = *configptr1;
    *configptr1 = tempVal;
}

//----------------------------------------------------------------------------
// Brief: check_and_alert fucntion to check computedStats.max is greater than 
// maxThreshold.
// Return: None
//----------------------------------------------------------------------------
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold )
    {
        alerters[0]();
        alerters[1]();
    }
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

    int elementcount=0;
    int elementmin=0;
    int elementmax=0;
    float sum=0.0;
    float elementset[setlength-1];

    for(elementcount=0; elementcount <setlength; elementcount++)
    {
      elementset[elementcount] = numberset[elementcount]; /* numberset elements input's are taken from stats-test.cpp */ 
    }

    for(elementcount=0; elementcount <setlength; elementcount++)
    {
        sum = sum + elementset[elementcount];
    }

    s.average = (float) sum/setlength; /* Reports Calculated Average */ 
    
    for (elementcount=0;elementcount<setlength-1;elementcount++) /* calculate Min and Max */
    {
        elementmin=elementcount;
        for (elementmax=elementcount+1;elementmax<setlength;elementmax++)
        {
            if (elementset[elementmax]<elementset[elementmin])
            {
                elementmin=elementmax;
            }
        }
        swap(&elementset[elementmin], &elementset[elementcount]);   
    }
    s.max = elementset[setlength-1];               /* Reports Calculated max  */ 
    s.min = elementset[0];                         /* Reports Calculated min  */ 

    return s;   /* added return Value */
}

void emailAlerter(void)
{
    emailAlertCallCount++;
}

void ledAlerter(void)
{
    ledAlertCallCount++;
}
