#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "decode.h"

// Funções de Leitura
// Ler percurso pré-ordem da árvore
char* percurso() {
	char *percurso = NULL;
	char aux;
	int counter = 0;
	do {
		scanf("%c", &aux);
		percurso = (char*)realloc(percurso, sizeof(char*) * counter + 1);
		percurso[counter] = aux;
		counter++;
	} while (aux != 10);
	return percurso;
}
// Ler mensagem comprimida (bits)
int *comprimida() {
	int *comprimida = NULL;
	char aux;
	int counter = 0;
	do {
		scanf("%c", &aux);
		comprimida = (int*)realloc(comprimida, sizeof(int) * counter + 1);
		comprimida[counter] = aux;
		counter++;
	} while (aux != 10);
}

// Funções de Descompressão

void descomprime();

// Impressão

// Tabela
void tabela() {
	printf("\tcaractere\tbits\tcodificação\n");
	printf("\t--------------------\n");
}

void imprime_dados(ARVORE_PREFIXO *arvore) {
	tabela();
}

