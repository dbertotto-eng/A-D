#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

Lista *crialista(void);
void inserelista(Lista *l, int valor);
void exibe(Lista *l);
void libera(Lista *l);

#endif