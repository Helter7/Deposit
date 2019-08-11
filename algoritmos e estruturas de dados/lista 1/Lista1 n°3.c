#include<stdio.h>
#include<stdlib.h>
// treino de recursividade lista do "Mestre" nº3
int Enesimo_Fibonacci(int e)
{
    int c;
    if(e == 1 || e == 2) return 1;
    else{
        return c = Enesimo_Fibonacci(e-2)+ Enesimo_Fibonacci(e-1);
    }
}
void main()
{
    printf("--Serie de Fibonacci--\n\n");

    int termo;

    printf("Que termo voce deseja conhecer?\n");
    scanf("%d",&termo);

    printf("O termo em questao e!\n[%d]",Enesimo_Fibonacci(termo));

}
