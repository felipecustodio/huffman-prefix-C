#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"

// Funções de leitura dentro do arquivo
// Ler percurso pré-ordem da árvore
char* ler_string_arquivo(FILE *arquivo) {
	
	char *string = NULL;
	char aux = '@';
	int contador = 0;
	while (aux != 10) {
		fscanf(arquivo, "%c", &aux);
		string = (char*)realloc(string, sizeof(char*) * contador + 1);
		string[contador] = aux;
		contador++;
	}
	string[contador-1] = '\0';
	return string;
	
}

// Função auxiliar para ler strings
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

// Abrir e ler arquivo de entrada
void ler_arquivo(char **preordem, char **mensagem) {

	char *nome_arquivo = NULL;
	printf("\tDigite o nome do arquivo a ser lido: ");
	nome_arquivo = ler_string();

	FILE *arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL) {
		printf("\tO arquivo não pôde ser aberto.\n");
		exit(0);
	}
	*(preordem) = ler_string_arquivo(arquivo);
	*(mensagem) = ler_string_arquivo(arquivo);
	fclose(arquivo);
	free(nome_arquivo);

}