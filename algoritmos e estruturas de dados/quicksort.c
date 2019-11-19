//agorithm quick sort
#include<stdio.h>

void exibir(int lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("%d|",lista[i]);
    }
}
//function of swap items
void swap(int *a,int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
//recursive function quick sort
void quicksort_rec(int lista[],int ini, int fim)
{
    int i=ini, j=fim, pos=(ini+fim)/2, pivo=lista[pos];

    if(ini<fim)
    {
        while(i<j)
        {
            while(lista[i]<pivo)
                i++;
            while(lista[j]>pivo)
                j--;
            if(lista[i] == pivo)
                pos=i;
            else if(lista[j] == pivo)
                pos=j;
            swap(&lista[i],&lista[j]);
        }
        quicksort_rec(lista,pos+1,fim);
        quicksort_rec(lista,ini,pos);
    }
}
//interface for the user
void quicksort_interface(int lista[],int tam)
{
    quicksort_rec(lista,0,tam-1);
}
//function quick sort with pivo on the first position
void quicksort_rec_2(int lista[],int ini, int fim)
{
    int i=ini, j=fim, pos = ini, pivo=lista[pos];

    if(ini<fim)
    {
        while(i<j)
        {
            while(lista[i]<pivo)
                i++;
            while(lista[j]>pivo)
                j--;
            if(lista[i] == pivo)
                pos=i;
            else if(lista[j] == pivo)
                pos=j;
            swap(&lista[i],&lista[j]);
        }
        quicksort_rec(lista,pos+1,fim);
        quicksort_rec(lista,ini,pos);
    }
}
//interface for the user
void quicksort_interface_2(int lista[],int tam)
{
    quicksort_rec_2(lista,0,tam-1);
}
main()
{
    int lista[7]={5,8,4,9,2,7,98} , tam=7;
    printf("\nUnordered List\n");
    exibir(lista,tam);
    quicksort_interface_2(lista,tam);
    printf("\nOrdered List\n");
    exibir(lista,tam);

}
