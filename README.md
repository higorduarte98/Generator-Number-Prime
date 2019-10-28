Este projeto escrito em linguagem C, implementa diferentes versões de um algoritmo para gerar numeros primos entre um intervalo.
Existem implementações com threads, fork e sem threads e fork.
A implementação com thread usa por padrão 4 threads. 
O numero de threads pode ser alterado na diretiva #define nThreads no arquvivo GeneratorNumberPrimeThread.c


## Compilação

Para compiilar siga os passos abaixo:

1. Abra o terminal do linux na pasta do projeto.
2. Digite chmod +x compile.sh
3. Digite ./compile.sh

---

## Execução

./gnp [LIMITE INFERIOR] [LIMITE SUPERIOR] [OPÇÃO] [MODO] 

---

## Teste

Para executar os testes siga os passos abaixo:

1. Abra o terminal do linux na pasta do projeto.
2. Digite chmod +x test.sh
3. Digite ./test.sh