#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "GeneratorNumberPrime.h"
#include "GeneratorNumberPrimeFork.h"
#include "GeneratorNumberPrimeThread.h"
#include "GeneratorNumberPrimeBasic.h"

void GeneratorNumberPrime ( unsigned long lowerLimit, unsigned long topLimit, Options op, Mode mode ) {

    if(mode == NORMAL_MODE){
        switch (op)
        {
            case BASIC_OPTION:
                GeneratorNumberPrimeBasic(lowerLimit, topLimit);
                break;
            case THREAD_OPTION:
                GeneratorNumberPrimeThread(lowerLimit, topLimit);
                break;
            case FORK_OPTION:
                GeneratorNumberPrimeFork(lowerLimit, topLimit);
                break;    
            default:
                break;
        }
    }
    else if(mode == ANALYSE_MODE)
    {
        switch (op)
        {
            case BASIC_OPTION:
                GeneratorNumberPrimeBasicAnalyse(lowerLimit, topLimit);
                break;
            case THREAD_OPTION:
                GeneratorNumberPrimeThreadAnalyse(lowerLimit, topLimit);
                break;
            case FORK_OPTION:
                GeneratorNumberPrimeForkAnalyse(lowerLimit, topLimit);
                break;    
            default:
                break;
        }
    }
    
    
}