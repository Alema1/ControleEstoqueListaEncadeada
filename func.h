#ifndef _BIBLIO_H_INCLUDED
#define _BIBLIO_H_INCLUDED
struct lista{
	int cod;
	char nome[20];
	char desc[40];
	float valor;
	int quant;

	struct lista* prox;
};

typedef struct lista no;


void inicia(no *LISTA);
int printmenu(void);
void option(no *LISTA, int op);
void insere(no *LISTA);
void busca(no *LISTA);
void exibeEstoque(no *LISTA);

#endif
