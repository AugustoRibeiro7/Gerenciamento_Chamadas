#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "fila.h"

void createfila(fila *f){
  f->inicio =NULL;
  f->fim    =NULL;
}


int fila_vazia(fila *f){

  if(f->inicio==NULL){
    return 1; // FILA VAZIA
  }else{
    return 0; // FILA NAO VAZIA
  }
}

void insere_fila(fila *f, char *peca, int quantidade, char *cliente, char *prioridade, int cont){

  chamados *novo = malloc(sizeof(chamados));
  strcpy(novo->peca, peca);
  novo->quantidade = quantidade;
  strcpy(novo->cliente, cliente);
  strcpy(novo->prioridade, prioridade);
  novo->cont = cont;
  novo->prox = NULL;

  if(fila_vazia(f)==1)
    {
        f->inicio = novo;
        f->fim = novo;
    }
  else
    {
        if (strcmp(prioridade, "gerente") == 0 || strcmp(prioridade, "Gerente") == 0)
        {
            if(strcmp(f->inicio->prioridade, "funcionario") == 0)
            {
               novo->prox = f->inicio;
               f->inicio = novo;
            }
            else
            {
                chamados *aux = f->inicio;
                while(aux->prox != NULL && strcmp(aux->prox->prioridade, "funcionario") != 0)
                {
                    aux = aux->prox;
                }
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }
        else
        {
           f->fim->prox = novo;
           f->fim = novo;
        }
    }

    novo=NULL;
    free(novo);
}


void remove_fila(fila *f)
{

    chamados *aux=malloc(sizeof(chamados));

    aux=f->inicio;

    f->inicio = aux->prox;


    aux->prox = NULL;

    if(f->inicio==NULL)
    {
        f->fim=NULL;
        free(aux);
    }
    else
    {
       free(aux);
    }
}


void mostrar_fila(fila *f)
{

   chamados *aux=malloc(sizeof(chamados));

    aux = f->inicio;

    while(aux!= NULL)
    {
        printf("\n\n\t Solicitante: %s",aux->cliente);
        printf("\n\n Cargo: %s",aux->prioridade);
        printf("\n Peca: %s",aux->peca);
        printf("\n Quantidade: %d",aux->quantidade);
        aux=aux->prox;
    }
   free(aux);

}
