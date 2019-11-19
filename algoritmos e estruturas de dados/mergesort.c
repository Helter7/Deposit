//agorithm merge sort with another structure as the item
#include<stdio.h>
typedef struct Carro{
    char* placa[8];
    char* marca[15];
    char* modelo[20];
    int ano;
}carro;

void exibir(carro lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("%d|",lista[i].);
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
//recursive function merge sort
void mergesort_rec(carro lista[],int ini, int fim)
{
    int pos=(ini+fim)/2,i=ini,j=pos+1,k=0,lista_aux[fim-ini+1];

    if(ini<fim)
    {
        mergesort_rec(lista,ini,pos);
        mergesort_rec(lista,pos+1,fim);

        while(i <= pos || j <= fim)
        {
            if(i > pos){
                lista_aux[k]=lista[j];
                j++;
            }
            else if(j > fim){
                lista_aux[k]=lista[i];
                i++;
            }
            else if(lista[i]<lista[j]){
                lista_aux[k]=lista[i];
                i++;
            }
            else{
                lista_aux[k]=lista[j];
                j++;
            }
            k++;
        }
        k=0;
        for(i=ini;i<=fim;i++){
            lista[i]=lista_aux[k];
            k++;
        }
    }
}
//interface of merge sort for the user
void mergesort(carro lista[],int tam)
{
    mergesort_rec(lista,0,tam-1);
}

main()
{
    int lista[7]={5,8,4,9,2,7,98} , tam=7;
    printf("\nUnordered List\n");
    exibir(lista,tam);
    mergesort(lista,tam);
    printf("\nOrdered List\n");
    exibir(lista,tam);
}
