#include "pilhasimplesencadeada.h"

main()
{
    pilha pilha;
    pilha = pilha_ler();
    pilha_exibir(pilha);
    pilha_remover(&pilha);
    pilha_exibir(pilha);
}
