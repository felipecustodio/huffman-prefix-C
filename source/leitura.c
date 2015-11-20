#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"

// Funções de leitura de arquivo

// Funções de leitura dentro do arquivo
// Ler percurso pré-ordem da árvore
char* percurso(FILE *arquivo) {
	char *percurso = NULL;
	char aux;
	int contador = 0;
	do {
		fscanf(arquivo, "%c", &aux);
		percurso = (char*)realloc(percurso, sizeof(char*) * contador + 1);
		percurso[contador] = aux;
		contador++;
	} while (aux != 10);
	return percurso;
}
// Ler mensagem comprimida (bits)
char *comprimida(FILE *arquivo) {
	char *comprimida = NULL;
	char aux;
	int contador = 0;
	do {
		fscanf(arquivo, "%c", &aux);
		comprimida = (char*)realloc(comprimida, sizeof(char) * contador + 1);
		comprimida[contador] = aux;
		contador++;
	} while (aux != 10);
	return comprimida;
}

char* ler_string() {
	
	char* string = NULL;
	char valor = '@';
	int contador = 0;

	while (valor != 10) {

		scanf("%c", &valor);
		string = (char*)realloc(string, sizeof(char) * contador + 1);
		
		string[contador] = valor;		
		contador++;

	}

	string[contador-1] = '\0';

	return string;

}

void ler_arquivo(char **preordem, char **mensagem) {

	char *nome_arquivo = NULL;
	printf("\tDigite o nome do arquivo a ser lido: ");
	nome_arquivo = ler_string();

	FILE *arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL) {
		printf("\tO arquivo não pôde ser aberto.\n");
		exit(0);
	}
	*(preordem) = percurso(arquivo);
	*(mensagem) = comprimida(arquivo);
	fclose(arquivo);
	printf("\tLeitura concluída\n");
	free(nome_arquivo);

}