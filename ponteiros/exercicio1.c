#include<stdio.h>

int main(){

    int i = 3, j = 5;
    int *p, *q;
    int valor;

    p = &i;
    q = &j;

    //A)
    valor = *p;

    printf("A) %d\n", valor);

    //B)
    valor = *p - *q;

    printf("B) %d\n", valor);

    //C)
    valor = **&p;

    printf("C) %d\n", valor);

    //D)
    valor =  3 - *p / (*q) + 7;

    printf("D) %d", valor);

    return 0;
}