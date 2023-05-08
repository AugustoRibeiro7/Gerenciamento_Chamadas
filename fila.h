#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct chamados
{
    char peca[30];
    int quantidade;
    char cliente[30];
    char prioridade[20];
    int cont;
    struct chamados *prox;
}chamados;

typedef struct fila
{
    chamados *inicio;
    chamados *fim;
}fila;

// PROTOTIPOS DAS FUNCOES

void createfila(fila *f);
int fila_vazia(fila *f);
void insere_fila(fila *f, char *peca, int quantidade, char *cliente, char *prioridade, int cont);
void remove_fila(fila *f);
void mostrar_fila(fila *f);


#endif // FILA_H_INCLUDED
