#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeneratorNumberPrime.h"

int main(int argc, char** argv){
    
    if(argc == 4){
        
        char *p = NULL;

        unsigned int lowerLimit = strtoul(argv[1], &p, 10);
        unsigned int topLimit = strtoul(argv[2], &p, 10);
        int option = atoi(argv[3]);

        switch (option)
        {
            case BASIC_MODE:
                GeneratorNumberPrime(lowerLimit, topLimit, BASIC_MODE);
                break;
            case THREAD_MODE:
                GeneratorNumberPrime(lowerLimit, topLimit, THREAD_MODE);
                break;
            case FORK_MODE:
                GeneratorNumberPrime(lowerLimit, topLimit, FORK_MODE);
                break;
        
            default:
                break;
        }
    }

    else{
        printf("\ngnp [LOWER LIMIT] [TOP LIMIT] [OPÇÃO]\n\nOPÇÃO:\n");
        printf("\t0 - Implementação sem threads e sem fork.\n");
        printf("\t1 - Implementação com threads.\n");
        printf("\t2 - Implementação com fork.\n\n");
    }
}