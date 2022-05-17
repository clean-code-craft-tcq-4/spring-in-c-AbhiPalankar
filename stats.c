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

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

    int elementcount=0;
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

    s.average = (float) sum/setlength; /* Calculate Average */ 
}
