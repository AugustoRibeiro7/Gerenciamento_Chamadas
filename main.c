/*
Nome: Augusto Paiva Ribeiro
*/
//==========================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "gerenciador.h"
#include "fila.h"

#define tam 10

void menu()
{
    estoque *stock = malloc(sizeof(estoque));
    create_estoque(stock);

    fila *f = malloc(sizeof(fila));
    createfila(f);

    int opc;

    do
    {
        printf("\n\t ===MENU===");
        printf("\n 1- Administador");
        printf("\n 2- Cliente");
        printf("\n 3- Fechar Sistema");
        printf("\n Digite a opcao..: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:{
                int op;
                do
                {
                    system("cls");
                    printf("\n\t ===ADMINISTRADOR===");
                    printf("\n\n 1- Inserir no estoque");
                    printf("\n 2- Mostrar estoque");
                    printf("\n 6- Voltar ao menu principal");
                    printf("\n 3- Fechar Sistema");
                    printf("\n Digite a opcao..: ");
                    scanf("%d", &op);
                    system("cls");

                    switch(op)
                    {
                        case 1:{
                            char nome[30];
                            int quant;
                            printf("\n Digite o nome do produto..: ");
                            fflush(stdin);
                            gets(nome);

                            printf("\n Digite a quantidade de produtos disponiveis..: ");
                            fflush(stdin);
                            scanf("%d", &quant);

                            inserir_estoque(stock, quant, nome);
                            break;
                        }
                        case 2:{
                            mostrar(stock);
                            getch();
                            break;
                        }
                        case 3:{
                            printf("\n Sistema encerrado.. \n\n");
                            opc = 3;
                            break;
                        }
                        case 6:{
                            op = 3;
                            opc = 6;
                            break;
                        }
                    }
                }while(op != 3);

                break;
            }
            case 2:{
                opc = 6;
                char nome[30], posicao[20];

                system("cls");
                printf("\n\t ===CADASTRO===");
                printf("\n\n Digite o nome do solicitante..: ");
                fflush(stdin);
                gets(nome);

                printf("\n Digite sua posicao profissional(gerente ou funcionario)..: ");
                fflush(stdin);
                gets(posicao);

                int escolha;
                int cont =0;
                do
                {
                    system("cls");
                    printf("\n\t ===CLIENTE===");
                    printf("\n\n 1- Realizar pedido");
                    printf("\n 2- Imprimir relatorio de pedidos realizados");
                    printf("\n 3- Imprimir relatorio de pedidos em espera");
                    printf("\n 4- Finalisar solicitacao");
                    printf("\n Digite a opcao..: ");
                    scanf("%d", &escolha);

                    switch(escolha)
                    {
                        case 1:{
                            char peca[30];
                            int quantidade;
                            printf("\n\n Digite o nome da peca/material solicitado..: ");
                            fflush(stdin);
                            gets(peca);

                            printf("\n\n Digite a quantidade requerida..: ");
                            scanf("%d", &quantidade);

                            cont++;
                            insere_fila(f, peca, quantidade, nome, posicao, cont);
                            break;
                        }
                        case 2:{
                            mostrar_fila(f);
                            getch();
                            break;
                        }
                        case 3:{
                            break;
                        }
                        case 4:{
                            printf("\n\n Pedido Finalizado com Sucesso..");
                            getch();
                        }
                    }
                }while(escolha != 4);

                system("cls");
                break;

            }
            case 3:{
                printf("\n Sistema encerrado.. \n\n");
                opc = 3;
            }


        }
    }while(opc == 6);
}


//==========================================================
//=========== CODIGO PRINCIPAL =============================
//==========================================================

int main()
{
   //CONFIGURAR ACENTUAÇÃO
    setlocale(LC_ALL,"Portuguese");


    menu();

    return 0;
}
