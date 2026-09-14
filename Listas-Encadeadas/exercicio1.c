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

    novo->info = dado;

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

    novo->info = dado;
    novo->prox = NULL;//novo->prox vai ser nulo pois é a ultima variavel

   

    if (listaVazia(lista))
    {
        lista->pFirst = novo;
    }else{
         Nodo *aux = lista->pFirst;//lista->pFisrst é a cabeça
        while (aux->prox != NULL)
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
        return 0;
    }
    Nodo *aux1, *aux2;

    aux1 = lista->pFirst;
    aux2 = aux1->prox;

    free(aux1);

    lista->pFirst = aux2;
    return 0;
}

int removerFinal(Head *lista){
    if (listaVazia(lista))
    {
        printf("Lista Vazia");
        return 0;
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

    return 0;
}

int buscar(Head *lista, int cod, Dados *resultado){

    Nodo *aux;
    
    if (listaVazia(lista))
    {
        printf("Lista Vazia");
        return 0;
    }

    aux = lista->pFirst;

    while (aux != NULL)
    {
        if (cod == aux->info.cod)
        {
            resultado->cod = aux->info.cod;
            strcpy(resultado->nome, aux->info.nome);
            resultado->preco = aux->info.preco;
            return 1;
        }else{
            aux = aux->prox;
        }
    }
    return 0;
}

void imprimirLista(Head *lista){
    if (listaVazia(lista))
    {
        printf("Lista Vazia");
        return;
    }
    
    Nodo *aux;

    aux = lista->pFirst;

    while (aux != NULL)
    {
        printf("\n====================\n");
        printf("%d\n", aux->info.cod);
        printf("%s\n", aux->info.nome);
        printf("%.2f\n", aux->info.preco);

        aux = aux->prox;
    }
}

void liberaLista(Head *lista){
    if (listaVazia(lista))
    {
        printf("Lista Vazia");
        return;
    }
    
    Nodo *aux1, *aux2;

    aux1 = lista->pFirst;


    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->prox;

        free(aux2);
    }
    lista->pFirst = NULL;
}

int main(){
    Head *ini;

    ini = criaLista();

    int op = 0;
    Dados produto;

    while (op != -1)
    {
        printf("\n\n==========Escolha uma Opcao==========\n");
        printf("1 - Inserir no Inicio\n");
        printf("2 - Inserir no Final\n");
        printf("3 - Remover no Inicio\n");
        printf("4 - Remover no Final\n");
        printf("5 - Buscar pelo Cod\n");
        printf("6 - Imprimeir Lista\n");
        printf("7 - Liberar Lista\n");
        printf("-1 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Informe o Cod do produto: ");
            scanf("%d", &produto.cod);

            getchar();

            printf("Informe o nome do produto: ");
            fgets(produto.nome, 10, stdin);

            printf("Informe o preço do produto: ");
            scanf("%f", &produto.preco);

            inserirInicio(ini, produto);
            break;

        case 2:
            printf("Informe o Cod do produto: ");
            scanf("%d", &produto.cod);

            getchar();

            printf("Informe o nome do produto: ");
            fgets(produto.nome, 10, stdin);

            printf("Informe o preço do produto: ");
            scanf("%f", &produto.preco);

            inserirFinal(ini, produto);
            break;
        
        case 3:
            removerInicio(ini);
            break;
        
        case 4:
            removerFinal(ini);
            break;
        
        case 5:
        {
            int cod;
            Dados resultado;

            printf("Digite o Cod do produto: ");
            scanf("%d", &cod);
            if (buscar(ini, cod, &resultado))
            {
                printf("Produto Encontrado!!!\n");
                printf("%d\n", resultado.cod);
                printf("%s\n", resultado.nome);
                printf("%.2f", resultado.preco);
            }else{
                printf("Produto Não encontrado");
            }
            break; 
        } 
        case 6:
            imprimirLista(ini);
            break;

        case 7:
            liberaLista(ini);
            break;
        case -1:
            printf("Saindo...");
            break;
        
        default:
            printf("Opção invalida!!!");
            break;
        }
    }

    free(ini);

    return 0;
}