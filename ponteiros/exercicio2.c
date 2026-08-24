#include<stdio.h>

int main(){

    int i = 3, j = 5;
    int *p, *q;
    int valor = 0;

    p = &i;
    q = &j;

    //A)
    valor = (*p = *q);

    printf("A) %d\n", valor);

    //B)
    valor =  p = q;

    printf("B) %d\n", valor);

    //C)
    valor = *p = (*p + *q);

    printf("C) %d\n", valor);

    //D)
    valor =  q = &i;

    printf("D) %d\n", valor);
    valor = *q = 100;
     printf("D.2) %d", valor);

    return 0;
}