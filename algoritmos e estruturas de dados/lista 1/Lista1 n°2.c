#include<stdio.h>
#include<stdlib.h>
// treino de recursividade lista do "Mestre" nº2
int Menor(int v[],int colu)
{
    int x;
    if(colu == 1) return x = v[0];
    else{
        x = Menor(v,colu-1);
        if(x<v[colu-1])return x;
        else return x = v[colu-1];
    }
}
int Menorpon(int *vpon, int c)
{
    int k;
    if(c == 1) return k = vpon[0];
    else{
        k = Menorpon(vpon,c-1);
        if(k<vpon[c-1]) return k;
        else return k = vpon[c-1];
    }
}
void main()
{
    int colu;

    printf("Quantos espacos deseja em seu vetor?\n");
    scanf("%d",&colu);

    int v[colu];
    int *vpon = (int*)malloc(sizeof(int[colu]));

    for(int i = 0; i<colu; i++){
        printf("Insira um valor no espanco n %d: ",i+1);
        scanf("%d",&v[i]);
        vpon[i] = v[i];
    }
    printf("\n(Metodo Padrao)\nO Menor valor entre eles e?\n[%d]",Menor(v,colu));
    printf("\n(Metodo Ponteiro)\nO Menor valor entre eles e?\n[%d]",Menorpon(vpon,colu));
}
