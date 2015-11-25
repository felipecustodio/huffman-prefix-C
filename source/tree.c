#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

// Alocar novo nó
void criar_no(NO **novo) { 
	(*novo) = (NO*)malloc(sizeof(NO)); 
	if ((*novo) != NULL) { 
		(*novo)->esquerda = NULL; 
		(*novo)->direita = NULL; 
	} 
}

// Transformar entrada em arvore
char* adicionar_no(NO **inicio, char *entrada) {

	criar_no(inicio);
	(*inicio)->caractere = *entrada;
	if(*entrada == '*') {
		entrada = adicionar_no(&((*inicio)->esquerda), ++entrada);
		entrada = adicionar_no(&((*inicio)->direita), ++entrada);
	} else {
		return (entrada);
	}
}

// Verifica se nó é folha
int no_externo(NO *teste) {
	if((teste != NULL) && (teste->esquerda == NULL) && (teste->direita == NULL)) {
		return (1);
	} else {
		return (0);
	}
}

// Impressão da árvore em pré ordem
void pre_ordem(NO *raiz) { 
	if (raiz != NULL) {
		printf("%c", raiz->caractere);
		pre_ordem(raiz->esquerda);
		pre_ordem(raiz->direita);
	}
}

// Liberar memória heap
void apagar_arvore(NO *raiz) { 
	if (raiz != NULL) { 
		apagar_arvore(raiz->esquerda); 
		apagar_arvore(raiz->direita); 
		free(raiz); 
	}
}