#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha *pilha;

    Elem e1;
    Elem e2;
    Elem e3;

    Elem removido;

    pilha = criaPilha();

    reset(pilha);

    e1.value = 10.5;
    e2.value = 20.5;
    e3.value = 30.5;

    push(pilha, e1);
    push(pilha, e2);
    push(pilha, e3);

    printf("Quantidade de elementos: %d\n", size(pilha));

    printf("\nElementos da pilha:\n");
    print(pilha);

    printf("\nElemento do topo:\n");
    top(pilha);

    removido = pop(pilha);

    printf("\nElemento removido: %.2f\n", removido.value);

    printf("\nPilha depois do pop:\n");
    print(pilha);

    printf("\nQuantidade de elementos: %d\n", size(pilha));

    clear(pilha);

    printf("\nPilha depois do clear:\n");
    print(pilha);

    free(pilha);

    return 0;
}