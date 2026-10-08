#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct lista{
    int valor;
    struct lista *prox;
};

Lista *crialista(void){
    Lista *l = malloc(sizeof(Lista));

    if (l == NULL)
    {
        printf("ERRO!!!");
        exit(1);
    }

    l->prox = NULL;

    return l;
    
}

void inserelista(Lista *l, int valor){
    Lista *novo;

    novo = malloc(sizeof(Lista));

    if (novo == NULL)
    {
        printf("ERRO!!!");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = l->prox;
    l->prox = novo;
}

void exibe(Lista *l){
    Lista *aux;

    aux = l->prox;

    if (aux ==  NULL)
    {
        printf("Lista Vazia!!!\n");
        return;
    }
    while (aux != NULL)
    {
        printf("%d", aux->valor);
        aux = aux->prox;
    }
}

void libera(Lista *l){
    Lista *aux1, *aux2;

    aux1 = l->prox;

    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->prox;

        free(aux2);
    }
    l->prox = NULL;
}