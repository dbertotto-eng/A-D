#include<stdio.h>
#include "lista.h"

int main(){

    Lista *l;

    l = crialista();

    int op = 0;

    while (op != -1)
    {
        printf("Escolha uma das opçções a baixo\n");
        printf("1 -- Inserir um elemento\n");
        printf("2 -- Exibir Lista\n");
        printf("3 -- Liberar lista\n");
        printf("-1 -- Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:{
            int valor;
            printf("Digite o valor que deseja inserir:");
            scanf("%d", &valor);
            inserelista(l, valor);
            break;
        }

        case 2:
            exibe(l);
            break;
        case 3:
            libera(l);
            break;
        case -1:
            printf("Encerrando programa\n");
            printf("Saindo...");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    }
    

    return 0;
}