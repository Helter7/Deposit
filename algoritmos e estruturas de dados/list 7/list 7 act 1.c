//list 7 activity 1
#include "listaduplamenteencadeada.h"

int lista_fim(lista lista)
{
    no_dup_enc *no;
    no = lista;
    while(no != NULL){
        if(no->proximo == NULL)
            break;
        no = no->proximo;
    }
    printf("Este e o fim da lista! |%d|",no->elemento);
    return no;
}
 main()
 {
     lista lista;
     lista = lista_ler();
     lista_exibir(lista);
     lista_fim(lista);
 }
