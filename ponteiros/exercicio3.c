#include<stdio.h>

int main(){
    int v[5];
    int *p;
    int valor;
    
    //A)
    valor = (p =v);

    printf("A) %d\n", valor);

    //B)
    valor =  (p = &v);

    printf("B) %d\n", valor);

    //C)
    valor = (p = &v[0]);

    printf("C) %d\n", valor);

    //D)
    //valor =  (v = p);

    //printf("D) %d\n", valor);
    
    //E
    valor = (p = v + 2);

    printf("E) %d", valor);

    return 0;
}