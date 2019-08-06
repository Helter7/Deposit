#include<stdio.h>

void hanoi(int num_disco, char torre_A, char torre_B, char torre_C)
{
    if(num_disco > 0)
    {
        hanoi(num_disco-1,torre_A,torre_C,torre_B);
        printf("Mover: %c -> %c\n",torre_A,torre_B);
        hanoi(num_disco-1,torre_C,torre_B,torre_A);
    }
}
main()
{
    int num_disco = 4;
    char torre_A = 'a';
    char torre_C = 'c';
    char torre_B  = 'b';

    hanoi(num_disco,torre_A,torre_B,torre_C);
}
