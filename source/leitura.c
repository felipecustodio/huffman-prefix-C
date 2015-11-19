#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"

// Funções de leitura de arquivo
void ler_arquivo() {

	FILE *entrada = NULL;
	char *nome_arquivo = NULL;
	char *percurso = NULL;
	int *mensagem = NULL;
	size_t tamanho_entrada;

	printf("\tARQUIVO DE ENTRADA: ");
	nome_arquivo = getline(stdin, &tamanho_entrada);

	entrada = fopen(nome_arquivo, "r");
	
	do {
		
	} while (feof(entrada));

}

// *** trocar scanf por fscanf *** 


// Funções de leitura dentro do arquivo
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
	return comprimida;
}
