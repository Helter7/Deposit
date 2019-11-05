//lista 5 atividade 1 Algoritmos e Estruturas de Dados
#include<stdio.h>
#include<stdlib.h>

int lista_inserir ( int elem , lista * lista )
{
    no_enc *no , *novo , *ant;

    if( lista == NULL )
        return REFERENCIA_INCORRETA;
    if( lista_obter_no_elemento ( elem ,* lista ) != NULL )
        return ELEMENTO_EXISTENTE;
    novo = lista_criar_no ( elem );
    if( *lista == NULL )
        *lista = novo;
    else{
        ant = *lista;
        no = ant->proximo;
        if(ant->elemento > elem){
            *lista = novo;
            novo->proximo = ant;
        }
        else{
            while ( no != NULL )
            {
                if(no->elemento > elem)
                    break;
                ant = ant->proximo;
                no = no->proximo;
            }
            novo->proximo = no;
            ant->proximo = novo;
        }
    }
    return SUCESSO;
 }
