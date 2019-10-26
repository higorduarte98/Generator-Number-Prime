#ifndef GeneratorNumberPrime_h
#define GeneratorNumberPrime_h
#define TRUE 1
#define FALSE 0

// FUNÇÃO QUE GERA NUMEROS PRIMOS ENTRE UM INTERVALO
void *GeneratorNumberPrime ( unsigned long, unsigned long );

// VERIFICA SE É PRIMO
int isPrime( unsigned long);

//VERSÃO THREAD
void GeneratorNumberPrimeThread ( unsigned long, unsigned long );

#endif