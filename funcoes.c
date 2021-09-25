#include <stdlib.h>
#include <stdio.h>
#include "func.h"

void inicia(no *LISTA)
{
	LISTA->prox = NULL;
}

int printmenu(void)
{
	int opcao;

	printf("Menu:\n");
	printf("(1) - Inserir produto\n");
	printf("(2) - Buscar produto\n");
	printf("(3) - Excluir produto\n");
	printf("(4) - Exibir estoque\n");
	printf("(5) - Sair do programa\n");
	printf("(6) - Limpar o Prompt\n\n");
	printf("Opcao:"); scanf("%d", &opcao);
	printf("\n\n");

	return opcao;
}

void option(no *LISTA, int opcao)
{
	switch(opcao){
		case 1:
			insere(LISTA);
			break;

		case 2:
			busca(LISTA);
			break;

		case 4:
			exibeEstoque(LISTA);
			break;
		case 5:
			exit(1);
			break;
		case 6:
			system("cls");
			break;

		default:
			printf("Digite um comando valido...\n\n");
	}
}

int listaVazia(no *LISTA)
{
	if(LISTA -> prox == NULL)                                        //verifica se a lista esta vazia
		return 1;
	else
		return 0;
}


void insere(no *LISTA)
{
	no *novo=(no *) malloc(sizeof(no));
	if(!novo){
		printf("Erro de alocacao!\n");
		exit(1);
	}
    printf("Codigo: "); scanf("%i", &novo -> cod);
	printf("Nome: "); scanf("%s", &novo -> nome);
	printf("Descricao: "); scanf("%s", &novo -> desc);
	printf("Valor: "); scanf("%f", &novo -> valor);
	printf("Quantidade: "); scanf("%i", &novo -> quant);
	printf("\n\n");
	printf("Produto inserido!");
	Sleep(1000);
	system("cls");

	no *ant = LISTA->prox;

	LISTA -> prox = novo;
	novo -> prox = ant;
}

void busca(no *LISTA){
	no *temp;
	temp = LISTA -> prox;
	int codig;
	int flag = 0;
	printf("Digite o codigo do produto a ser buscado:\n");
	scanf("%i", &codig);
	while(temp != NULL){
		if(temp -> cod == codig){
			printf(" %i \t\t",temp -> cod);
			printf(" %s \t\t",temp -> nome);
			printf(" %s \t\t",temp -> desc);
			printf(" %f \t",temp -> valor);
			printf(" %i ",temp -> quant);
			flag = 1;
			temp = NULL;
		}
		else
			temp = temp->prox;
	}
	if(!flag) printf("produto não encontrado na lista");
}

void exibeEstoque(no *LISTA)
{
	if(listaVazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

	no *temp;
	temp = LISTA -> prox;

	printf("Codigo\t\tNome\t\tDescricao\t\tValor\t    Quantidade\n");

	while( temp != NULL){
	printf(" %i \t\t",temp -> cod);
	printf(" %s \t\t",temp -> nome);
	printf(" %s \t\t\t",temp -> desc);
	printf(" %f \t",temp -> valor);
	printf(" %i ",temp -> quant);
		 temp = temp -> prox;
	printf("\n");
	}
	printf("\n\n");
}
