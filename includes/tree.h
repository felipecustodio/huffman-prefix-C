#include <stdio.h>
#include <stdlib.h>

// Definições
// Árvore de busca como lista ligada

typedef struct no NO;
typedef struct arvore ARVORE_PREFIXO;

struct no {

	char caractere;
	NO *proximo;
	NO *anterior;

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
// Busca
int busca(NO *raiz, int chave);
// Número de Nós
int conta_nos(NO *raiz);
// Inserção
NO* novo(char valor, NO* esquerda, NO* direita);
int insere(NO *raiz, char valor);
// Percurso Pré-Ordem
void __pre_order(NO *raiz);
void pre_order(ARVORE_PREFIXO* arvore);