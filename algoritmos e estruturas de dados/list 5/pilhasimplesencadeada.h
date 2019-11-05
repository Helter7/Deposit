//Pilhas simplesmente encadeadas
#include<stdio.h>
#include<stdlib.h>
#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define SUCESSO -3
#define PILHA_VAZIA -4
#define ELEMENTO_INEXISTENTE -5

typedef struct _no_enc no_enc ;
typedef struct _no_enc* pilha ;

typedef struct _no_enc {
int elemento ;
no_enc * proximo ;
};

 no_enc * pilha_criar_no ( int dado )
 {
 no_enc * no = (no_enc *)malloc ( sizeof ( no_enc ) ) ;
 no -> elemento = dado ;
 no -> proximo = NULL ;
 return no ;
 }


 int pilha_numero_elementos ( pilha pilha ){
 int tam =0;
 no_enc * no = pilha ;
 if( no == NULL )
 return 0;
 while ( no != NULL )
 {
 no = no -> proximo ;
  tam ++;
  }
  return tam ;
 }


 no_enc * pilha_obter_no_elemento ( int elem ,pilha pilha ){
 no_enc * no = pilha ;
 while ( no != NULL )
 {
 if( no -> elemento == elem )
 return no ;
 no = no -> proximo ;
 }
  return NULL ;
 }


int pilha_inserir(int elem,pilha *pilha)
{
    no_enc *novo, *no;

    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    if(pilha_obter_no_elemento(elem,*pilha) != NULL)
    return ELEMENTO_EXISTENTE;

    novo = pilha_criar_no(elem);

    if(*pilha == NULL)
        *pilha = novo;
    else{
        no = *pilha;
        *pilha = novo;
        novo->proximo = no;
    }
    return SUCESSO;
}


 int pilha_remover(pilha *pilha)
 {
    no_enc *no,*ant;
    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    if(*pilha == NULL)
        return PILHA_VAZIA;
    //removendo
    no = *pilha;
    if(no->proximo == NULL){
        free(*pilha);
        *pilha = NULL;
    }
    else{
        *pilha = no->proximo;
        free(no);
    }
    return SUCESSO;
 }


 void pilha_exibir ( pilha pilha ){
 no_enc * no = pilha ;
 if( no != NULL )
 while ( no != NULL )
 {
 printf ("%d|",no -> elemento ) ;
 no = no -> proximo ;
 }
  printf ("\n") ;
 }


 pilha pilha_ler (){
 pilha l = NULL ;
 int i , elem , qtd ;
 printf (" Informe quantos elementos desejainserir :") ;
 scanf ("%d" ,& qtd ) ;
 for ( i =0; i < qtd ; i ++){
 printf (" LISTA [%d]= ",i ) ;
  scanf ("%d" ,& elem ) ;
  pilha_inserir ( elem ,& l ) ;
 }
  return l ;
 }


 void pilha_desalocar ( pilha *pilha ){
  no_enc * no , * prx ;
  if( pilha != NULL )
  if( *pilha != NULL )
  {
  no = *pilha ;
  prx = no -> proximo ;
  while ( no != NULL )
  {
  free ( no ) ;
  no = prx ;
  if( prx != NULL )
  prx = prx -> proximo ;
 }
 }
 *pilha = NULL ;
 }
