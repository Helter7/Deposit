//algorithm bubble sort
#include <stdio.h>

//function of swap items
void swap(int *a,int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// function bubble sort recursion
void bubblesort(int lista[],int tam)
{
    int i;
    if(tam>0){
        for(i=0;i<tam-1;i++)
            if(lista[i]>lista[i+1])
                swap(&lista[i],&lista[i+1]);
        bubblesort(lista,tam-1);
    }
}
//function bubble sort without recursion
void bubble_no_recursion(int lista[],int tam)
{
    int i, k;
    for(k=0;k<tam-1;k++){
        for(i=0;i<tam -k -1;i++)
            if(lista[i]>lista[i+1])
                swap(&lista[i],&lista[i+1]);
    }
}
void exibir(int lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("%d|",lista[i]);
    }
}
main()
{
    int lista[7]={5,8,4,9,2,7,4} , tam=7;
    printf("\nUnordered List\n");
    exibir(&lista,tam);
    bubble_no_recursion(&lista,tam);
    printf("\nOrdered List\n");
    exibir(&lista,tam);

}
