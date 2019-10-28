#include <stdio.h>
#include <time.h>
#include "GeneratorNumberPrimeBasic.h"
#include "bool.h"
#include "LinkedList.h"

inline bool isPrime(unsigned long n){

    // O MENOR NUMERO PRIMO É 2, LOGO SE n FOR MENOR QUE 2 n NÃO É PRIMO
    if(n < 2) return FALSE;

    // n = 2 É PRIMO
    if(n == 2) return TRUE;

    // SE n É PAR E DIFERENTE DE 2 ENTÃO n NÃO É PRIMO
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

void GeneratorNumberPrimeBasic ( unsigned long lowerLimit, unsigned long topLimit )  {

    LinkedList *list = lstCreate();    

    // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
    for(unsigned long i = lowerLimit; i <= topLimit; i++){
        if(isPrime(i))
            lstInsert(list, i);
    }

    lstPrint(list);
    printf("\n");
}

void GeneratorNumberPrimeBasicAnalyse ( unsigned long lowerLimit, unsigned long topLimit){
    LinkedList *list = lstCreate();    

    // MEDINDO TEMPO TOTAL DAS THREADS
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
    for(unsigned long i = lowerLimit; i <= topLimit; i++){
        if(isPrime(i))
            lstInsert(list, i);
    }

    //IMPRIMI TEMPO GASTO
    clock_gettime(CLOCK_MONOTONIC, &finish);

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    printf("Tempo total: %.2lf s\n", (double)seconds + (double)ns/(double)1000000000); 
}