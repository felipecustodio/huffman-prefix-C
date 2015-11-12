#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Funções de Leitura

char* percurso() {
	char *percurso = NULL;
	char aux;
	int counter = 0;
	do {
		scanf("%c", &aux);
		percurso = (char*)realloc(percurso, sizeof(char*) * counter + 1);
		percurso[counter] = aux;
		counter++/
	} while (aux != 10);
	return percurso;
}

int *comprimida() {
	int *comprimida = NULL;
	char aux;
	int counter = 0;
	do {
		scanf("%c", &aux);
		comprimida = (int*)realloc(comprimida, sizeof(int) * counter + 1);
		comprimida[counter] = aux;
		counter++
	} while (aux != 10);
}

// Funções de Descompressão

void descomprime();





