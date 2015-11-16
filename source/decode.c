#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Funções de Árvore

void arvore_entrada(char *percurso); // transformar entrada pré-ordem em árvore


// Funções de Descompressão
void descomprime(int* comprimida) {

	char *mensagem = NULL;
	int total_bits = 0;
	int bits_descomprimidos = 0;
	int total_caracteres = 0;
	double taxa_compressao = 0;

	total_caracteres = strlen(mensagem);

	// Cálculo da taxa de compressão
	bits_descomprimidos = sizeof(char) * total_caracteres;
	taxa_compressao = (double)total_bits/(double)bits_descomprimidos;
	taxa_compressao = taxa_compressao * 100;

	// Impressão dos dados
	printf("\tMENSAGEM DESCOMPRIMIDA\n");
	printf("\t%s\n", mensagem);
	printf("\tNúmero de bits\t= %d", total_bits);
	printf("\tNúmero de caracteres\t=  %d" total_caracteres);
	printf("\tTaxa de compressão\t= %ld", taxa_compressao);

}

// Tabela
void tabela() {
	printf("\tcaractere\tbits\tcodificação\n");
	printf("\t--------------------\n");
}