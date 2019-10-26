#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "GeneratorNumberPrime.h"
#include "GeneratorNumberPrimeFork.h"
#include "GeneratorNumberPrimeThread.h"
#include "GeneratorNumberPrimeBasic.h"

void GeneratorNumberPrime ( unsigned long lowerLimit, unsigned long topLimit, Options op ) {

    switch (op)
    {
        case BASIC_MODE:
            GeneratorNumberPrimeBasic(lowerLimit, topLimit);
            break;
        case THREAD_MODE:
            GeneratorNumberPrimeThread(lowerLimit, topLimit);
            break;
        case FORK_MODE:
            GeneratorNumberPrimeFork(lowerLimit, topLimit);
            break;    
        default:
            break;
    }
    
}