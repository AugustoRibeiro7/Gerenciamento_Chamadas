#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "gerenciador.h"


void create_estoque(estoque *storage)
{
    storage->topo = NULL;
}

int estoque_vazio(estoque *stock)
{
    if(stock->topo == NULL){
        return 1; // PILHA VAZIA
    }else{
        return 0; // PILHA NAO VAZIA
    }
}

void inserir_estoque(estoque *peca, int quant, char *nome)
{
    Testoque *novo = malloc(sizeof(Testoque));
    novo->quantidade = quant;
    strcpy(novo->nome, nome);

    novo->ant = peca->topo;
    peca->topo = novo;

    novo = NULL;
    free(novo);
    return;
}

void mostrar(estoque *stock){

  Testoque *aux;
  aux = stock->topo;

  while(aux !=NULL){
    printf("\n\n %s",aux->nome);
    printf("\n %d",aux->quantidade);
    aux=aux->ant;
  }
}
