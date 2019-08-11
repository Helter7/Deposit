#include<stdio.h>
#include<stdlib.h>
// treino de recursividade lista do "Mestre" nº1
int Maior(int v[],int t)
{
    int x;
    if(t == 1) return x = v[0];
    else{
        x = Maior(v,t-1);
        if(x>v[t-1]) return x;
        else{
            return x = v[t-1];
        }
    }
}
int Maiorpon(int *vpon,int t)
{
    int x;
    if(t == 1) return x = vpon[0];
    else{
        x = Maior(vpon,t-1);
        if(x>vpon[t-1]) return x;
        else{
            return x = vpon[t-1];
        }
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
  printf("\n(Metodo Padrao)\nO Maior valor entre eles e?\n[%d]",Maior(v,colu));
  printf("\n(Metodo Ponteiro)\nO Maior valor entre eles e?\n[%d]",Maiorpon(vpon,colu));
}
