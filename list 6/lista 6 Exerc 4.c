#include<stdio.h>
#include<stdlib.h>
/* Escreva uma função para ordenar um vetor em ordem crescente*/
void EscreverVt(int vt[],int colu)
{
    for(int i = 0 ; i<colu; i++)
        printf("[%d]",vt[i]);
}

void crescenteVt(int vt[],int colu)
{
    int aux,i,j;

    for(i=0; i<colu-1; i++)
    {
        for(j=0; j<colu-1; j++)
        {
            if(vt[j]>vt[j+1])
            {
                aux = vt[j];
                vt[j] = vt[j+1];
                vt[j+1] = aux;
            }
        }
    }
}

void crescenteVp(int *vp,int colu)
{
    int aux,i,j;

    for(i=0; i<colu-1; i++)
    {
        for(j=0; j<colu-1; j++)
        {
            if(vp[j]>vp[j+1])
            {
                aux = vp[j];
                vp[j] = vp[j+1];
                vp[j+1] = aux;
            }
        }
    }
}

main()
{
    int colu;

    printf("Diga um numero inteiro de colunas do vetor: "); scanf("%d",&colu);

    int vt[colu];
    int *vp = (int*)malloc(sizeof(int[colu]));

    for(int i = 0; i<colu; i++)
    {
        printf("Qual o valor do vetor na posicao %d : ",i); scanf("%d",&vt[i]);
        vp[i] = vt[i];
    }

    crescenteVt(vt,colu);
    crescenteVp(vp,colu);

    printf("\nVetor em forma crescente:\n");
    EscreverVt(vt,colu);

    printf("\nPonteiro em forma crescente:\n");
    EscreverVt(vp,colu);
}
