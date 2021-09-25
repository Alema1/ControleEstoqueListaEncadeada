//--------------------------
//Nome: Vinicius Hardt Schreiner
//Matricula: 201420108
//--------------------------

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
	no *LISTA = (no *) malloc(sizeof(no));                                 // alocação da cabeca da lista
	if(!LISTA){
		printf("Erro de alocacao!\n");
		exit(1);
	}
	inicia(LISTA);

	int opcao;

	do{
		opcao = printmenu();                                                // laco de execucao do menu
		option(LISTA,opcao);
	}while(opcao!=6);

	free(LISTA);
	return 0;
}


/*
Referencias bibliograficas:
Apostila de Estruturas de Dados, Waldemar Celes, Jose´ Lucas Rangel;
www.ime.usp.br
www.cprogressivo.com
www.inf.purs.br
www.inf.puc-rio.br
*/
