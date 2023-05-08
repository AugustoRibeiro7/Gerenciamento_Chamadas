#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED


// STRUCTS
typedef struct Testoque
{
    char nome[30];
    int quantidade;
    struct Testoque *ant;
}Testoque;

typedef struct estoque
{
    Testoque *topo;
}estoque;

//PROTOTIPOS FUNCOES
void create_estoque(estoque *storage);
int estoque_vazio(estoque *stock);
void inserir_estoque(estoque *peca, int quant, char *nome);
void mostrar(estoque *stock);

#endif // GERENCIADOR_H_INCLUDED
