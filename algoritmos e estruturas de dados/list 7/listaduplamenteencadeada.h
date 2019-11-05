//lista duplamente encadeada

#include<stdio.h>
#include<stdlib.h>
#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define SUCESSO -3
#define LISTA_VAZIA -4
#define ELEMENTO_INEXISTENTE -5

typedef struct _no_dup_enc no_dup_enc ;
typedef struct no_dup_enc * lista ;

typedef struct _no_dup_enc {
    int elemento ;
    no_dup_enc * proximo , * anterior ;
};

no_dup_enc * lista_criar_no (int dado )
{
    no_dup_enc * no = malloc ( sizeof ( no_dup_enc ) );
    no -> elemento = dado ;
    no -> proximo = no -> anterior = NULL ;
    return no ;
}

int lista_numero_elementos ( lista lista )
{
    int tam =0;
    no_dup_enc * no = lista ;
    while ( no != NULL )
    {
        no = no -> proximo ;
        tam ++;
    }
    return tam;
}

no_dup_enc * lista_obter_no_elemento ( int elem , lista lista )
{
    no_dup_enc * no = lista ;
    while ( no != NULL ){
        if( no -> elemento == elem )
            return no ;
        no = no -> proximo ;
    }
    return NULL ;
}

int lista_inserir ( int elem , lista * lista )
{
    no_dup_enc * no , * novo ;
    if( lista == NULL )
        return REFERENCIA_INCORRETA ;
    if( lista_obter_no_elemento ( elem ,* lista ) != NULL )
        return ELEMENTO_EXISTENTE ;
    novo = lista_criar_no ( elem ) ;
    if( * lista == NULL )
        *lista = novo ;
    else{
        no = * lista ;
            while ( no -> proximo != NULL )
                no = no -> proximo ;
        no -> proximo = novo ;
        novo -> anterior = no ;
    }
    return SUCESSO ;
}

int lista_remover ( int elem , lista * lista )
{
    no_dup_enc * no , * ant , * prox ;
    if( lista == NULL )
        return REFERENCIA_INCORRETA ;
    if( *lista == NULL )
        return LISTA_VAZIA ;
    if( lista_obter_no_elemento ( elem ,* lista ) == NULL )
        return ELEMENTO_INEXISTENTE ;
    no = * lista ;
    if( no -> elemento == elem ){
    no = no -> proximo ;
    free ( * lista ) ;
    *lista = no ;
    if( no != NULL )
        no -> anterior = NULL ;
    }
    else{
        no = no -> proximo ;
    while ( no != NULL ){
        if( no -> elemento == elem ){
            ant = no -> anterior ;
            prox = no -> proximo ;
            ant -> proximo = prox ;
            if( prox != NULL )
                prox -> anterior = ant ;
            free ( no ) ;
            break ;
        }
        no = no -> proximo ;
    }
    }
    return SUCESSO ;
}

void lista_exibir ( lista lista )
{
    no_dup_enc * no = lista ;
    while ( no != NULL ){
        printf ("%d|",no -> elemento ) ;
        no = no -> proximo ;
    }
    printf ("\n") ;
}

lista lista_ler ()
{
    lista l = NULL ;
    int i , elem , qtd ;
    printf (" Informe quantos elementos deseja inserir :") ;
    scanf ("%d" ,& qtd ) ;
    for ( i =0; i < qtd ; i ++){
        printf (" LISTA [%d]= ",i ) ;
        scanf ("%d" ,& elem ) ;
        lista_inserir ( elem ,& l ) ;
    }
    return l ;
}

void lista_desalocar ( lista * lista )
{
    no_dup_enc * no , * prox ;
    if( lista != NULL )
        if( * lista != NULL ){
            no = * lista ;
            prox = no -> proximo ;
            while ( no != NULL ){
                free ( no ) ;
                no = prox ;
                if( prox != NULL )
                    prox = prox -> proximo ;
            }
        }
    *lista = NULL ;
}
