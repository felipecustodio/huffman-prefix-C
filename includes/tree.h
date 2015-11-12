#include <stdio.h>
#include <stdlib.h>

// Definições

typedef struct no NO;
typedef struct arvore ARVORE_PREFIXO;

typedef struct no {

	char caractere;
	//ARVORE_PREFIXO *sub_esquerda;
	//ARVORE_PREFIXO *sub_direita;

} NO;

typedef struct arvore {

	NO *raiz;

} ARVORE_PREFIXO;

// Funções

// Leitura
char* percurso();
int* comprimida();
// Descompressão
void descomprime();
