#include<stdio.h>

void min_max(int *v, int n, int *min, int *max)
{
    *min = *v;
    *max = *v;

    for (int i = 1; i < n; i++)
    {
        if (*(v + i) < *min)
        {
            *min = *(v + i);
        }

        if (*(v + i) > *max)
        {
            *max = *(v + i);
        }
    }
}

int main(){

int n;
int min = 0;
int max = 0;

printf("Digite o tamanho do vetor: ");
scanf("%d", &n);

int v[n];

for (int i = 0; i < n; i++)
{
    printf("Digite o algarismo na posição %d do vetor: ", i);
    scanf("%d", &v[i]);
}

for (int i = 0; i < n; i++)
{
    printf("[%d]", v[i]);
}

min_max(v, n, &min, &max);

printf("\nMenor valor: %d", min);
printf("\nMaior valor: %d", max);
    return 0;
}