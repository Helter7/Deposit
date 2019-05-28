#include<stdio.h>
#include<stdlib.h>
/* Escrever uma função para receber uma matriz ponteiro e dar a media aritmetica*/
float mediaMt (float **mt, int lin, int colu, int div)
{
    int i,j;
    float soma = 0.0;
    // Somando
    for( i = 0; i<colu; i++)
        for(j = 0; j<lin; j++)
            soma = mt[i][j] + soma;

    //Média
    div = (lin*colu)- div;
    soma = soma/div;
    return soma;
}
void main()
{
    /* pedindo numero de linhas e colunas e informando espaços vagos
    e sobre como lidar com espaços adjacentes*/
    int lin,colu;

    printf("Media Aritmetica");
    printf("\nInforme um numero inteiro de linhas para a tabela: ");scanf("%d",&lin);
    printf("\nInforme um numero inteiro de colunas para a tabela: ");scanf("%d",&colu);

    int qtd = lin*colu;

    printf("\nVoce possui %d espacos vagos para os numeros do calculo.\nCaso o numero exceda o necessario digite '0'.\n",qtd);

    /*preenchendo espaços e lidando com sobras*/
    float **mt = (float**)malloc(sizeof(float[lin][colu]));

    int i,j;
    for(i = 0; i<colu; i++)
    {
        for(j = 0; j<lin; j++)
        {
            printf("\nInforme os Valores a serem calculados: ");scanf("%f",&mt[i][j]);

            if(mt[i][j] == 0)
            {
                printf("\nTabela completa Calculando Media");
                break;
            }
            if(qtd != 1)
            {
                qtd--;
                printf("\nQtd de espacos vagos (%d)",qtd);
            }
                else
                    qtd--;

        }
    }
    printf("\n\nSua media e : %f",mediaMt(mt,lin,colu,qtd));
    free(mt);
}
