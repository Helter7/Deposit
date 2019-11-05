//lista simplesmente encadeadas
#include<stdio.h>
#include<stdlib.h>
#define REFERENCIA_INCORRETA -1
#define ELEMENTO_EXISTENTE -2
#define SUCESSO -3
#define LISTA_VAZIA -4
#define ELEMENTO_INEXISTENTE -5

typedef struct _no_enc no_enc ;
typedef struct _no_enc* lista ;

typedef struct _no_enc {
int elemento ;
no_enc * proximo ;
};

 no_enc * lista_criar_no ( int dado )
 {
 no_enc * no = (no_enc *)malloc ( sizeof ( no_enc ) ) ;
 no -> elemento = dado ;
 no -> proximo = NULL ;
 return no ;
 }


 int lista_numero_elementos ( lista lista ){
 int tam =0;
 no_enc * no = lista ;
 if( no == NULL )
 return 0;
 while ( no != NULL )
 {
 no = no -> proximo ;
  tam ++;
  }
  return tam ;
 }


 no_enc * lista_obter_no_elemento ( int elem ,lista lista ){
 no_enc * no = lista ;
 while ( no != NULL )
 {
 if( no -> elemento == elem )
 return no ;
 no = no -> proximo ;
 }
  return NULL ;
 }


 int lista_inserir ( int elem , lista * lista ){
 no_enc * no , * novo ;
 if( lista == NULL )
 return REFERENCIA_INCORRETA ;
 if( lista_obter_no_elemento ( elem ,* lista ) !=NULL )
 return ELEMENTO_EXISTENTE ;
 novo = lista_criar_no ( elem ) ;
 if( * lista == NULL )
  * lista = novo ;
  else
 {
  no = * lista ;
  while ( no -> proximo != NULL )
  no = no -> proximo ;
  no -> proximo = novo ;
 }
  return SUCESSO ;
 }


 int lista_remover ( int elem , lista * lista ){
 if( lista == NULL )
 return REFERENCIA_INCORRETA ;
 if( * lista == NULL )
 return LISTA_VAZIA ;
 no_enc * no , * ant ;
 if( lista_obter_no_elemento ( elem ,* lista ) ==NULL )
  return ELEMENTO_INEXISTENTE ;
 no = * lista ;
  if( no -> elemento == elem )
 {
  no = no -> proximo ;
  free ( * lista ) ;
  * lista = no ;
 }
 else{
 ant = no ;
 no = no -> proximo ;
 while ( no != NULL )
 if( no -> elemento == elem )
 {
 ant -> proximo = no -> proximo ;
 free ( no ) ;
  break ;
 }
  ant = no ;
  no = no -> proximo ;
 }
  return SUCESSO ;
 }


 void lista_exibir ( lista lista ){
 no_enc * no = lista ;
 if( no != NULL )
 while ( no != NULL )
 {
 printf ("%d|",no -> elemento ) ;
 no = no -> proximo ;
 }
  printf ("\n") ;
 }


 lista lista_ler (){
 lista l = NULL ;
 int i , elem , qtd ;
 printf (" Informe quantos elementos desejainserir :") ;
 scanf ("%d" ,& qtd ) ;
 for ( i =0; i < qtd ; i ++){
 printf (" LISTA [%d]= ",i ) ;
  scanf ("%d" ,& elem ) ;
  lista_inserir ( elem ,& l ) ;
 }
  return l ;
 }


 void lista_desalocar ( lista * lista ){
  no_enc * no , * prx ;
  if( lista != NULL )
  if( * lista != NULL )
  {
  no = * lista ;
  prx = no -> proximo ;
  while ( no != NULL )
  {
  free ( no ) ;
  no = prx ;
  if( prx != NULL )
  prx = prx -> proximo ;
 }
 }
 * lista = NULL ;
 }
