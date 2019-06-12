#include"implementacoesIniciais.h"

void distribuiPecas(TJogoDeDomino*); //FALTA PROGRAMAR – MATRIZES E TIPOS
void arquivaPecasDeJogador(TJogoDeDomino, int, FILE**); // FALTA PROGRAMAR - ARQUIVOS
void arquivoTxtParaBin(FILE**, FILE**, int); //FALTA PROGRAMAR - ARQUIVOS
int  geraCodigo(TPecaDeDomino); //FALTA PROGRAMAR – RACIOCÍNIO LÓGICO
void imprimePecasComCodigosGerados(TJogoDeDomino*);

//NÃO MODIFICAR!!!
void imprimePecasComCodigosGerados(TJogoDeDomino *jogo)
{
  int i;
  for(i = 0; i < pecas; i = i+1)
  {
    //(*jogo).pecasDoJogo[i].codigo = geraCodigo((*jogo).pecasDoJogo[i]);
    imprimePeca((*jogo).pecasDoJogo[i]);
  }
  printf("\n");
}
void distribuiPecas(TJogoDeDomino* jogo)
{
    int i,j,k,c;
    for(i = 0; i< jogadores; i++)
        for( j = 0; j< maoInicial; j++)
        {
            c = 0;
            while(c == 0)
            {
              k = rand() % 28;
                if((*jogo).pecasDoJogo[k].codigo != -1)
                {
                    (*jogo).pecasDosJogadores[i][j] = (*jogo).pecasDoJogo[k] ;
                    (*jogo).pecasDoJogo[k].codigo = (TValor)-1;
                    (*jogo).pecasDoJogo[k].face1 = (TValor)-1;
                    (*jogo).pecasDoJogo[k].face2 = (TValor)-1;
                    c = c+2;
                }
            }
        }
}
void arquivaPecasDeJogador(TJogoDeDomino jogo, int i, FILE**arqTxt)
{
    int j;
    for(j = 0;j<maoInicial;j++)
        if(jogo.pecasDosJogadores[i][j].codigo != -1)
        {
                fprintf(
                        *arqTxt,
                        "%2d ---> %d | %d\n",
                        jogo.pecasDosJogadores[i][j].codigo,
                        jogo.pecasDosJogadores[i][j].face1,
                        jogo.pecasDosJogadores[i][j].face2
                        );
        }
}
void arquivoTxtParaBin(FILE**f1, FILE**f2, int k)
{
    TPecaDeDomino trans;
    rewind(*f1);
    while(1)
    {
        if(feof(*f1))break;
        fscanf(*f1,"%2d ---> %d | %d\n",&trans.codigo,&trans.face1,&trans.face2);
        fwrite(&trans,k,1,*f2);
    }
}
main()
{
  TJogoDeDomino jogo;
  FILE * arqTxt, *arqBin;
  int i;

  iniciaPecasDoJogo(&jogo);
  imprimePecasComCodigosGerados(&jogo);
  imprimePecasDoJogo(jogo);

  distribuiPecas(&jogo);
  imprimePecasDosJogadores(jogo);

  arqTxt = fopen("jogador1.txt", "w+");
  arquivaPecasDeJogador(jogo, 0, &arqTxt);

  arqBin = fopen("jogador1.dat", "wb+");
  arquivoTxtParaBin(&arqTxt, &arqBin, sizeof(TPecaDeDomino));

  fclose(arqTxt);
  fclose(arqBin);
}
