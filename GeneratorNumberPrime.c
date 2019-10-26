#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "GeneratorNumberPrime.h"


void *GeneratorNumberPrime ( unsigned long lowerLimit, unsigned long topLimit ) {

    printf("\n");

    // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
    for(unsigned long i = lowerLimit; i <= topLimit; i++){
        if(isPrime(i))
            printf("%lu ", i);
    }

    printf("\n\n");
}

void GeneratorNumberPrimeThread ( unsigned long lowerLimit, unsigned long topLimit ) { 
    pthread_t p1;
    pthread_t p2;

    pthread_create(&p1, NULL, GeneratorNumberPrime(lowerLimit, topLimit), NULL);
    pthread_create(&p2, NULL, GeneratorNumberPrime(lowerLimit, topLimit), NULL);

    pthread_join(p1, NULL);
    //pthread_join(p2, NULL);
}

int isPrime(unsigned long n){

    // O MENOR NUMERO PRIMO É 2, LOGO SE n FOR MENOR QUE 2 n NÃO É PRIMO
    if(n < 2) return FALSE;

    // n = 2 É PRIMO
    if(n == 2) return TRUE;

    // SE n É PAR ENTÃO n NÃO É PRIMO
    if(n % 2 == 0)
        return FALSE;

    // SE n FOR MAIOR QUE 2 E PRIMO ENTÃO n É IMPAR
    // NUMÉRO ÍMPAR SÓ É DIVISIVEL POR NUMERO ÍMPAR
    // SE n TEM DIVISOR MAIOR QUE raiz (n) ENTÃO TAMBÉM TEM DIVISOR MENOR QUE raiz (n)
    // i <= raiz(n) = i^2 <= n
    // ASSUMINDO QUE TODO NUMERO É DIVISIVEL POR 1 E POR ELE MESMO. PORTANTO SOMENTE É NECESSARIO VERIFICAR
    // SE n É DIVISIVEL POR UM NUMERO IMPAR ENTRE 3 E raiz(n) 
    for(unsigned long i = 3; i*i <= n; i = i+2){
        if(n % i == 0) {
            return FALSE;
        }
    }

    return TRUE;
}