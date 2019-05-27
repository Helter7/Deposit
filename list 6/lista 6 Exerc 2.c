#include<stdio.h>
#include<stdlib.h>
// lista 7 exer 1
void escrevervt(int vt[],int colunas)
{
  for(int i = 0; i < colunas; i++){
        printf("[%d]",vt[i]);
  }

    printf("\n");
}
void Multvt(int vt[],int colu)
{
    for(int i = 0; i < colu; i++){
        vt[i] = vt[i]*i;
    }
}
void Multpon(int *vpon,int colu)
{
    for(int i = 0; i < colu; i++){
        vpon[i] = vpon[i]*i;
    }
}
main()
{
    int coluna;

    printf("Qual o numero de colunas? ");scanf("%d",&coluna);

    int v[coluna];
    int *vpon = (int*)malloc(sizeof(int[coluna]));

    for(int i = 0; i < coluna; i++) {
    printf("Forneca um valor inteiro para a posicao %d : ",i);
    scanf("%d",&v[i]);
    vpon[i] = v[i];
    }
    printf("\nValor inicial do vetor:\n");
    escrevervt(v,coluna);

    printf("\nValor inicial do vetor ponteiro:\n");
    escrevervt(vpon,coluna);

    Multvt(v,coluna);
    Multpon(vpon,coluna);

    printf("\nValor multiplicado do vetor:\n");
    escrevervt(v,coluna);

    printf("\nValor multiplicado do vetor ponteiro:\n");
    escrevervt(vpon,coluna);
}
