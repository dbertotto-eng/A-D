#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct nodo {
    Elem info;
    struct nodo *prox;
} Nodo;

struct pilha {
    Nodo *topo;
    int qtd;
};

Pilha *criaPilha()
{
    Pilha *pilha;

    pilha = malloc(sizeof(Pilha));

    if (pilha == NULL)
    {
        printf("Erro de memoria!\n");
        exit(1);
    }

    pilha->topo = NULL;
    pilha->qtd = 0;

    return pilha;
}

void reset(Pilha *pilha)
{
    pilha->topo = NULL;
    pilha->qtd = 0;
}

int empty(Pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        return 1;
    }

    return 0;
}

int size(Pilha *pilha)
{
    return pilha->qtd;
}

void push(Pilha *pilha, Elem elem)
{
    Nodo *novo;

    novo = malloc(sizeof(Nodo));

    if (novo == NULL)
    {
        printf("Erro de memoria!\n");
        exit(1);
    }

    novo->info = elem;
    novo->prox = pilha->topo;

    pilha->topo = novo;
    pilha->qtd++;
}

Elem pop(Pilha *pilha)
{
    Nodo *aux;
    Elem elem;

    if (empty(pilha))
    {
        printf("Pilha vazia!\n");

        elem.value = 0;

        return elem;
    }

    aux = pilha->topo;

    elem = aux->info;

    pilha->topo = aux->prox;

    free(aux);

    pilha->qtd--;

    return elem;
}

void top(Pilha *pilha)
{
    if (empty(pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Topo: %.2f\n", pilha->topo->info.value);
}

void clear(Pilha *pilha)
{
    Nodo *aux;

    while (pilha->topo != NULL)
    {
        aux = pilha->topo;

        pilha->topo = aux->prox;

        free(aux);
    }

    pilha->qtd = 0;
}

void print(Pilha *pilha)
{
    Nodo *aux;

    if (empty(pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }

    aux = pilha->topo;

    while (aux != NULL)
    {
        printf("%.2f\n", aux->info.value);

        aux = aux->prox;
    }
}