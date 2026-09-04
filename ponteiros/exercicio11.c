#include<stdio.h>
#include<stdlib.h>

int *concatenar(int *v1, int n1, int *v2, int n2,
int *n3){
    int tam = n1 + n2;
    int *p;
    p = malloc(tam * sizeof(int));
    if (p == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
    {
        p[i] = v1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        p[n1 + i] = v2[i];
    }

    *n3 = tam;
    return p;
}

int main(){

    int n1, n2;
    int n3;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n1);

    int v1[n1];
    
    for (int i = 0; i < n1; i++)
    {
        printf("Digite os valeres do vetor: ");
        scanf("%d", &v1[i]);
    }
    
    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);

    int v2[n2];

    for (int i = 0; i < n2; i++)
    {
        printf("Digite os valores do vetor 2: ");
        scanf("%d", &v2[i]);
    }
    
    int *v3 = concatenar(v1,n1,v2,n2,&n3);

    for (int i = 0; i < n3; i++)
    {
        printf("%d ", v3[i]);
    }

    printf("\ntamanho do v3: %d", n3);
    

    free(v3);
    v3 = NULL;

    return 0;
}