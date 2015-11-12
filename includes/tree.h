#include <stdio.h>
#include <stdlib.h>

// Definições

typedef struct no NO;
typedef struct arvore ARVORE_PREFIXO;

struct no {

	char caractere;
	NO *esquerda;
	NO *direita;

};

struct arvore {

	NO *raiz;
	int total_nos;
	int bits;

};

// Funções de Árvore

// Inicialização
NO* cria_no();
ARVORE_PREFIXO* cria_arvore();