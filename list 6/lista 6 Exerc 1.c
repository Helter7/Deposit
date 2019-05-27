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
void inverterVt (int vt[], int colunas)
{
    int i = colunas-1;
    int x = 0;
    int aux = 0;

    for(i; i >= (colunas/2); i--) {
        aux = vt[i];
        vt[i] = vt[x];
        vt[x] = aux;
        x = x + 1;
    }
}
void ponteiroVt(int *Vtpon, int colunas)
{
    int i = colunas-1;
    int x = 0;
    int aux = 0;

    for(i; i >= (colunas/2); i--) {
        aux = Vtpon[i];
        Vtpon[i] = Vtpon[x];
        Vtpon[x] = aux;
        x = x + 1;
    }
}

main()
{
    int colunas;

    printf("Informe o numero de colunas do vetor: ");
    scanf("%d",&colunas);

    int vetor[colunas];
    int*Vtpon = (int*)malloc(sizeof(int[colunas]));

    for(int i = 0; i < colunas; i++) {
    printf("Forneca um valor inteiro para a posicao %d : ",i);
    scanf("%d",&vetor[i]);
    Vtpon[i] = vetor[i];
    }

    printf("vetor inicial:\n");
    escrevervt(vetor,colunas);

    printf("vetor ponteiro inicial:\n");
    escrevervt(Vtpon,colunas);

    inverterVt(vetor,colunas);
    ponteiroVt(Vtpon,colunas);

    printf("vetor ivertido:\n");
    escrevervt(vetor,colunas);

    printf("vetor ponteiro invertido:\n");
    escrevervt(Vtpon,colunas);

    free(Vtpon);
}
