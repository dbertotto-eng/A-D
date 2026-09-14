#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
 int cod;
 char nome[10];
 float preco;
} Dados;//uma struct do tipo dados

typedef struct Nodo {
    Dados info;
    struct Nodo *prox;
} Nodo;//um nó com um tipo Dados info e o prox

typedef struct {
    Nodo *pFirst;
} Head;

Head *criaLista(){
    Head *le;

    le = (Head*)malloc(sizeof(Head));

    if (le == NULL)
    {
        printf("ERRO!!!");
        exit(1);
    }
    le->pFirst = NULL;
    
    return le;
}

int listaVazia(Head *lista){
    if (lista->pFirst == NULL)
    {
        return 1;
    }else{
        return 0;
    }
    
}

void inserirInicio(Head *lista, Dados dado){
    Nodo *novo;

    novo = (Nodo*)malloc(sizeof(Nodo));

    if (novo == NULL)
    {
        printf("Erro!!!");
        exit(1);
    }

    printf("Informe o codigo do produto: \n");
    scanf("%d", &novo->info.cod);
    getchar();

    printf("Informe o nome do produto: \n");
    fgets(novo->info.nome, 10, stdin);

    printf("Informe o preço do pruduto: \n");
    scanf("%f", &novo->info.preco);


    novo->prox = lista->pFirst;
    lista->pFirst = novo;
    
}

void inserirFinal(Head *lista, Dados dado){
    Nodo *novo;

    novo = (Nodo*)malloc(sizeof(Nodo));

    if (novo == NULL)
    {
        printf("ERRO!!!");
        exit(1);
    }

    printf("Informe o codigo do produto: \n");
    scanf("%d", &novo->info.cod);
    getchar();

    printf("Informe o nome do produto: \n");
    fgets(novo->info.nome, 10, stdin);

    printf("Informe o preço do pruduto: \n");
    scanf("%f", &novo->info.preco);

    novo->prox = NULL;//novo->prox vai ser nulo pois é a ultima variavel

   

    if (listaVazia(lista))
    {
        lista->pFirst = novo;
    }else{
         Nodo *aux = lista->pFirst;//lista->pFisrst é a cabeça
        aux = aux->prox;//para eu ver o prox da cabeça eu tenho que criar esse aux
        while (aux != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int removerInicio(Head *lista){
    if (listaVazia(lista))
    {
        printf("Lista Vazia");
        return;
    }
    Nodo *aux1, *aux2;

    aux1 = lista->pFirst;
    aux2 = aux1->prox;

    free(aux1);

    lista->pFirst = aux2;
    
}

int removerFinal(Head *lista){
    if (listaVazia(lista))
    {
        printf("Lista Vazia");
        return;
    }
    Nodo *aux1, *aux2;

    aux1 = lista->pFirst;
    aux1 = aux1->prox;
    while (aux1->prox->prox != NULL)
    {
        aux1 = aux1->prox;
    }
    aux2 = aux1->prox;
    free(aux2);
    aux1->prox = NULL;
}

int buscar(Head *lista, int cod, Dados *resultado);

void imprimirLista(Head *lista);

void liberaLista(Head *lista);

int main(){
    

    return 0;
}