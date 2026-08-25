#include<stdio.h>

void inverter(int *v, int n);
void soma(int *v, int n);
void troca_vizinhos(int *a, int *b);

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
    printf("\n");
    
    inverter(p, n);
    
    soma(p ,n);

    for (int i = 0; i < n - 1; i = i + 2)
    {    
        troca_vizinhos(&v[i], &v[i + 1]);   
    }
    printf("Vetor depois de trocar vizinhos: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(p + i));
    }
    printf("\n");
    return 0;
}

void inverter(int *v, int n){
    int aux;
    for(int i = 0; i < n / 2; i++){
        aux = *(v + i);
        *(v + i) = *(v + n - 1 - i);
        *(v + n - 1 - i) = aux;
    }
    printf("Vetor depois de inverter: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }
    printf("\n");
}

void soma(int *v, int n){
    int aux = 0;
    for(int i = 0; i < n; i++){
        aux += *(v + i);
    }
    printf("Soma dos elementos: %d\n", aux);
    
}

void troca_vizinhos(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}