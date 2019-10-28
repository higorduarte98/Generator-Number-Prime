#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeneratorNumberPrime.h"

int main(int argc, char** argv){
    
    // SE TIVER 5 ARGUMENTOS
    if(argc == 5){
        
        char *p = NULL;

        unsigned long lowerLimit = strtoul(argv[1], &p, 10);
        unsigned long topLimit = strtoul(argv[2], &p, 10);
        int option = atoi(argv[3]);
        int mode = atoi(argv[4]);

        switch (option)
        {
            case BASIC_OPTION:
                GeneratorNumberPrime(lowerLimit, topLimit, BASIC_OPTION, mode);
                break;
            case THREAD_OPTION:
                GeneratorNumberPrime(lowerLimit, topLimit, THREAD_OPTION, mode);
                break;
            case FORK_OPTION:
                GeneratorNumberPrime(lowerLimit, topLimit, FORK_OPTION, mode);
                break;
        
            default:
                break;
        }
    }

    else{
        printf("\ngnp [LIMITE INFERIOR] [LIMITE SUPERIOR] [OPÇÃO] [MODO]\n\n");
        printf("OPÇÃO:\n");
        printf("\t0 - Implementação sem threads e sem fork.\n");
        printf("\t1 - Implementação com threads.\n");
        printf("\t2 - Implementação com fork.\n\n");
        printf("MODO:\n");
        printf("\t0 - Modo normal.\n");
        printf("\t1 - Modo de medição de tempo de execução.\n");
    }
}