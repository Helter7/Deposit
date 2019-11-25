//agorithm merge sort with another structure as the item
#include<stdio.h>
#include<string.h>
typedef struct Carro{
    char* placa[8];
    char* marca[15];
    char* modelo[20];
    int ano;
}carro;

int compare_carro(carro lista[],int i, int k)
{
    return strcmp(lista[i].placa,lista[k].placa);
}

void exibir(carro lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("%s| %s| %s| %d\n",lista[i].marca,
                                lista[i].modelo,
                                lista[i].placa,
                                lista[i].ano);
    }
}
//recursive function merge sort
void mergesort_rec(carro lista[],int ini, int fim)
{
    int pos=(ini+fim)/2,i=ini,j=pos+1,k=0;
    carro lista_aux[fim-ini+1];

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
            else if(compare_carro(lista,i,j) < 0){
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
    carro carro1,carro2,carro3;
    int tam = 3;
    carro lista[3];

    strcpy(carro1.placa,"C"); //LPP8977
    strcpy(carro1.modelo,"Focus");
    carro1.ano = 2010;
    strcpy(carro1.marca,"Ford");

    strcpy(carro2.placa,"A"); //KMP9826
    strcpy(carro2.marca,"Volkswagen");
    strcpy(carro2.modelo,"Polo");
    carro2.ano = 2008;

    strcpy(carro3.placa,"B"); //AMP0927
    strcpy(carro3.marca,"Chevrolet");
    strcpy(carro3.modelo,"Corsa");
    carro3.ano=2012;

    lista[0] = carro1;
    lista[1] = carro2;
    lista[2] = carro3;

    printf("\nUnordered List\n");
    exibir(lista,tam);
    mergesort(lista,tam);
    printf("\nOrdered List\n");
    exibir(lista,tam);
}
