#include "GeneratorNumberPrimeThread.h"
#include "bool.h"
#include "LinkedList.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
#define nThreads 4

// LIMITE INFERIOR E SUPERIOR
typedef struct {
    unsigned long lowerLimit;
    unsigned long topLimit;
}Limits;

// ARGUMENTOS QUE SERÃO PASSADOS PARA AS THREADS
typedef struct {
    Limits *limits;
    LinkedList *list;
}Args;

// VERIFICA SE É PRIMO
bool isPrime(unsigned long n){

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
    
    for(unsigned long i = 3; i*i <= n; i = i + 2){
        if(n % i == 0) return FALSE;
    }

    return TRUE;
}

// METODO EXECUTADO PELA THREAD
void* run(void* arguments) {
    Args *args = (Args*) arguments;
    Limits *limits = args->limits;
    LinkedList *list = args->list;

    // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
    for(unsigned long i = limits->lowerLimit; i <= limits->topLimit; i++){

        // SE É PRIMO INSERE NA LISTA
        if(isPrime(i))
            lstInsert(list, i);
    }
}

void GeneratorNumberPrimeThread ( unsigned long lowerLimit, unsigned long topLimit ) {

    // DECLARANDO ARGUMENTOS DAS THREADS
    Args args[nThreads];

    // CRIANDO ARGUMENTOS PARA THREADS
    for(int i = 0; i < nThreads; i++){

        // ALOCA ESPAÇO PARA LIMITS E CRIA A LISTA
        args[i].limits = malloc(sizeof(Limits));
        args[i].list = lstCreate();

        // SETA VALORES DE LIMITES INFERIOR E SUPERIOR
        args[i].limits->lowerLimit = (i) * ( topLimit - lowerLimit ) / nThreads + lowerLimit + (i!=0);
        args[i].limits->topLimit = (i+1) * ( topLimit - lowerLimit ) / nThreads + lowerLimit;            
    }

    // DECLARANDO THREADS
    pthread_t pthreads[nThreads];
    
    // CRIANDO THREADS
    for(int i = 0; i < nThreads; i++){
        pthread_create(&pthreads[i], NULL, run, &args[i]);
    }

    // AGUARDA AS THREADS TERMINAREM
    for(int i = 0; i < nThreads; i++){
        pthread_join(pthreads[i], NULL);
    }

    //IMPRIME RESULTADO
    for(int i = 0; i < nThreads; i++)
        lstPrint(args[i].list);

    printf("\n");

    //LIBERA ARGUMENTOS DAS THREADS
    for(int i = 0; i < nThreads; i++){
        lstFree(args[i].list);
        free(args[i].limits);
    }
}

// METODO EXECUTADO PELA THREAD COM ANALISE
void* runAnalyse(void* arguments) {
    Args *args = (Args*) arguments;
    Limits *limits = args->limits;
    LinkedList *list = args->list;

    //CALCULA TEMPO GASTO POR CADA THREAD
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // GERA NUMEROS PRIMOS ENTRE LIMITE INFERIOR E LIMITE SUPERIOR
    for(unsigned long i = limits->lowerLimit; i <= limits->topLimit; i++){

        // SE É PRIMO INSERE NA LISTA
        if(isPrime(i))
            lstInsert(list, i);
    }

    //IMPRIMI TEMPO GASTO
    clock_gettime(CLOCK_MONOTONIC, &finish);
    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    printf("Tempo gasto pela thread: %.2lf s\n", (double)seconds + (double)ns/(double)1000000000); 
}

void GeneratorNumberPrimeThreadAnalyse ( unsigned long lowerLimit, unsigned long topLimit ){

    // DECLARANDO ARGUMENTOS DAS THREADS
    Args args[nThreads];

    // CRIANDO ARGUMENTOS PARA THREADS
    for(int i = 0; i < nThreads; i++){

        // ALOCA ESPAÇO PARA LIMITS E CRIA A LISTA
        args[i].limits = malloc(sizeof(Limits));
        args[i].list = lstCreate();

        // SETA VALORES DE LIMITES INFERIOR E SUPERIOR
        args[i].limits->lowerLimit = (i) * ( topLimit - lowerLimit ) / nThreads + lowerLimit + (i!=0);
        args[i].limits->topLimit = (i+1) * ( topLimit - lowerLimit ) / nThreads + lowerLimit;            
    }

    // DECLARANDO THREADS
    pthread_t pthreads[nThreads];
    
    // MEDINDO TEMPO TOTAL DAS THREADS
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // CRIANDO THREADS
    for(int i = 0; i < nThreads; i++){
        pthread_create(&pthreads[i], NULL, runAnalyse, &args[i]);
    }

    // AGUARDA AS THREADS TERMINAREM
    for(int i = 0; i < nThreads; i++){
        pthread_join(pthreads[i], NULL);
    }

    //IMPRIMI TEMPO GASTO
    clock_gettime(CLOCK_MONOTONIC, &finish);

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    printf("Tempo total: %.2lf s\n", (double)seconds + (double)ns/(double)1000000000); 

    //LIBERA ARGUMENTOS DAS THREADS
    for(int i = 0; i < nThreads; i++){
        lstFree(args[i].list);
        free(args[i].limits);
    }
}