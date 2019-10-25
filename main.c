#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeneratorNumberPrime.h"

int main(int argc, char** argv){

    if(argc == 4){
        
        char *p = NULL;

        unsigned int lowerLimit = strtoul(argv[1], &p, 10);
        unsigned int topLimit = strtoul(argv[2], &p, 10);

        if( strcmp(argv[3], "1") == 0 )
            GeneratorNumberPrime(lowerLimit, topLimit);
        else if( strcmp(argv[3], "2") == 0 )
            GeneratorNumberPrimeThread(lowerLimit, topLimit);
    }

    else{
        printf("\ngnp [LOWER LIMIT] [TOP LIMIT] [OPÇÃO]\n\nOPÇÃO:\n");
        printf("\t1 - Implementação sem threads e sem fork.\n");
        printf("\t2 - Implementação com threads.\n");
        printf("\t3 - Implementação com fork.\n\n");
    }
}