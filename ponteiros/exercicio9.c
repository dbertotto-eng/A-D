#include<stdio.h>
#include<stdlib.h>

 int *copia_vetor(int *v, int n){
    int *copia = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        copia[i] = v[i];
    }
    return copia;
 }

int main(){
    int n;
    int *copia;
    printf("Informe o tamanho do vetor: \n");
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    copia = copia_vetor(v, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", copia[i]);
    }
    
    free(copia);
    copia = NULL;

    return 0;
}