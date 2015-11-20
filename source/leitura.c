#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"

// Funções de leitura de arquivo

// Funções de leitura dentro do arquivo
// Ler percurso pré-ordem da árvore
char* percurso() {
	char *percurso = NULL;
	char aux;
	int contador = 0;
	do {
		scanf("%c", &aux);
		percurso = (char*)realloc(percurso, sizeof(char*) * contador + 1);
		percurso[contador] = aux;
		contador++;
	} while (aux != 10);
	return percurso;
}
// Ler mensagem comprimida (bits)
int *comprimida() {
	int *comprimida = NULL;
	char aux;
	int contador = 0;
	do {
		scanf("%c", &aux);
		comprimida = (int*)realloc(comprimida, sizeof(int) * contador + 1);
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