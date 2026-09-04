#include<stdio.h>
#include<stdlib.h>

int main (){

    int *p;
    int n = 1;

    p = malloc(n * sizeof(int));

    

    if (p == NULL)
    {
        printf("Probelma de memoria");
        exit(1);
    }
    
    p[0] = 0;

    int op = 0;

    while (op != -1)
    {
    printf("======Escolha uma opção======\n");
    printf("1 - Adicionar um novo valor\n");
    printf("2 - mostrar valores adicionados\n");
    printf("3 - Mostrar quantidade de elementos\n");
    printf("4 - Mostarar maior/menor valor\n");
    printf("-1 -Sair\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        n++;
        p = realloc(p, n * sizeof(int));
        if (p == NULL)
        {
            printf("Erro de memoria");
            exit(1);
        }
        printf("Digite o valor: \n");
        scanf("%d", &p[n-1]);
        
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", p[i]);
        }
        break;
    case 3:
        printf("%d elementos no vetor\n", n);
        break;
    case 4:
    {
        int max = p[0];
        int min = p[0];

        for (int i = 1; i < n; i++)
        {
        if (p[i] < min)
        {
            min = p[i];
        }

        if (p[i] > max)
        {
            max = p[i];
        }
        }
        printf("Valor menor: %d\n", min);
        printf("Valor maior: %d\n", max);
        break;
    }
        case -1:
        printf("Saindo...");
        break;
    
    default:
        printf("Valor invalido");
        break;
    }
    }

    free(p);
    p = NULL;

    return 0;
}