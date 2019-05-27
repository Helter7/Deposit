#include<stdio.h>
#include<stdlib.h>
/* Escrever função em arranjo e ponteiro para localizar o maior numero dentro de um vetor */
int EscreverVt(int vt[],int colu)
{
    int i;
    for(i = 0; i < colu; i++)
        printf("\n%d",vt[i]);
}

int MValorVt (int vt[],int colu)
{
    int i;
    int a = vt[0];

    for(i = 1; i<colu; i++)
    {
        if(vt[i]>a)
            a = vt[i];
    }
    return a;

}

int MValorPon (int *vp,int colu)
{
    int i;
    int a = vp[0];

    for(i = 1; i<colu; i++)
    {
        if(vp[i]>a)
            a = vp[i];
    }
    return a;
}
main()
{
    int colu;

    printf("Numero de Colunas: ");
    scanf("%d",&colu);

    int vt[colu];
    int *vp = (int*)malloc(sizeof(int[colu]));

    int i;

    for(i = 0; i<colu; i++)
    {
        printf("Forneca o numero para o vetor posicao %d:",i);
        scanf("%d",&vt[i]);
        vp[i]=vt[i];
    }

    printf("Valor no vetor convencional:\n%d",MValorVt(vt,colu));

    printf("\nValor no vetor com ponteiro:\n%d",MValorPon(vp,colu));

    free(vp);
}
