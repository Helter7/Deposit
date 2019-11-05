//list 5 activity 2

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

// forma utilizada em lista
 int pilha_inserir ( int elem , pilha *pilha ){
 no_enc * no , * novo ;
 if( pilha == NULL )
 return REFERENCIA_INCORRETA ;
 if( pilha_obter_no_elemento ( elem ,*pilha ) !=NULL )
 return ELEMENTO_EXISTENTE ;
 novo = pilha_criar_no ( elem ) ;
 if( *pilha == NULL )
  *pilha = novo ;
  else
 {
  no = *pilha ;
  while ( no -> proximo != NULL )
  no = no -> proximo ;
  no -> proximo = novo ;
 }
  return SUCESSO ;
 }

int pilha_remover(pilha *pilha)
 {
    no_enc *no,*ant;
    if(pilha == NULL)
        return REFERENCIA_INCORRETA;
    if(*pilha == NULL)
        return PILHA_VAZIA;
    //removendo
    ant = *pilha;
    no = ant->proximo;
    if(pilha_numero_elementos(*pilha) == 1)
        free(ant);
    else{
        free(ant);
        *pilha = no;
    }
    return SUCESSO;
 }

 //forma padrão de remover como na lista
int pilha_remover ( int elem , pilha *pilha ){
 if( pilha == NULL )
 return REFERENCIA_INCORRETA ;
 if( *pilha == NULL )
 return PILHA_VAZIA ;
 no_enc * no , * ant ;
 if( pilha_obter_no_elemento ( elem ,*pilha ) ==NULL )
  return ELEMENTO_INEXISTENTE ;
 no = *pilha ;
  if( no -> elemento == elem )
 {
  no = no -> proximo ;
  free ( *pilha ) ;
  *pilha = no ;
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
