#include<stdio.h>

void inverter(int *v, int n);

int main(){

    int v[100];
    int n;
    int *p = v;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    printf("Digite os valores do vetor: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    printf("Valores do vetor: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(p + i));
    }
    inverter(p, n);
    return 0;
}

void inverter(int *v, int n){
    int aux;
    for(int i = 0; i < n / 2; i++){
        aux = *(v + i);
        *(v + i) = *(v + n - 1 - i);
        *(v + n - 1 - i) = aux;
    }
    printf("Vetor depois de inverter: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }
}