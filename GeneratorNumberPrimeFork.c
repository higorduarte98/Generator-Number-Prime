#include "GeneratorNumberPrimeFork.h"
#include "bool.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// LIMITE INFERIOR E SUPERIOR
typedef struct {
    unsigned int lowerLimit;
    unsigned int topLimit;
}Limits;

// VERIFICA SE É PRIMO

 inline bool isPrime(unsigned long n){

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
        if(n % i == 0) return FALSE;
    }

    return TRUE;
}

void GeneratorNumberPrimeFork ( unsigned long lowerLimit, unsigned long topLimit ) {
    
    // PID
    pid_t pid;

    LinkedList * list = lstCreate();;

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    // PROCESSO FILHO
    if (pid == 0)
    {

        // MEDINDO TEMPO
        clock_t t = clock();

        // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
        for(unsigned long i = lowerLimit; i <= topLimit/2; i++){

            // SE É PRIMO INSERE NA LISTA
            if(isPrime(i))
                lstInsert(list, i);
        }

        printf("%lf", (clock() - t) / (double) CLOCKS_PER_SEC);
    }

    // PROCESSO PAI
    else
    {
         // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
        for(unsigned long i = ( topLimit - lowerLimit ) / 2 + lowerLimit + 1; i <= topLimit; i++){

            // SE É PRIMO INSERE NA LISTA
            if(isPrime(i))
                lstInsert(list, i);
        }

    }

    //IMPRIME RESULTADO
    lstPrint(list);

    printf("\n");

    //LIBERA LISTA
    lstFree(list);


    
    
}

void GeneratorNumberPrimeForkAnalyse ( unsigned long lowerLimit, unsigned long topLimit ){
    // PID
    pid_t pid;
    struct timespec start, finish;
    LinkedList * list = lstCreate();

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    // PROCESSO FILHO
    if (pid == 0)
    {
        // MEDINDO TEMPO DO PROCESSO
        clock_gettime(CLOCK_MONOTONIC, &start);

        // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
        for(unsigned long i = lowerLimit; i <= topLimit/2; i++){

            // SE É PRIMO INSERE NA LISTA
            if(isPrime(i))
                lstInsert(list, i);
        }

        //IMPRIMI TEMPO GASTO PELO PROCESSO PAI
        clock_gettime(CLOCK_MONOTONIC, &finish);

        long seconds = finish.tv_sec - start.tv_sec; 
        long ns = finish.tv_nsec - start.tv_nsec; 
        
        printf("Tempo do processo filho: %.2lf s\n", (double)seconds + (double)ns/(double)1000000000); 
    }

    // PROCESSO PAI
    else
    {
        // MEDINDO TEMPO TOTAL DAS THREADS
        clock_gettime(CLOCK_MONOTONIC, &start);

         // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
        for(unsigned long i = ( topLimit - lowerLimit ) / 2 + lowerLimit + 1; i <= topLimit; i++){

            // SE É PRIMO INSERE NA LISTA
            if(isPrime(i))
                lstInsert(list, i);
        }

        //IMPRIMI TEMPO GASTO PELO PROCESSO PAI
        clock_gettime(CLOCK_MONOTONIC, &finish);

        long seconds = finish.tv_sec - start.tv_sec; 
        long ns = finish.tv_nsec - start.tv_nsec; 
        
        printf("Tempo do processo pai: %.2lf s\n", (double)seconds + (double)ns/(double)1000000000); 

    }

    //LIBERA LISTA
    lstFree(list);
}