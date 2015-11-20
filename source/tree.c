#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NO* criar_arvore(void) { 
	NO *raiz = (NO*)malloc(sizeof(NO)); 
	if (raiz != NULL) { 
		raiz->esquerda = NULL; 
		raiz->direita = NULL; 
	} 
	return (raiz); 
}

NO* inserir_filho(int filho, NO *no, char valor) { 
	NO *novo = (NO*)malloc(sizeof(NO)); 
	if (novo != NULL) { 
		novo->direita = NULL; 
		novo->esquerda = NULL; 
		novo->caractere = valor; 
		if (filho == FILHO_ESQ) { 
			no->esquerda = novo; 
		} else { 
			no->direita = novo; 
		} 
	} 
	return (novo); 
}

void pre_ordem(NO *raiz) { 
	if (raiz != NULL) { 
		printf("%c", raiz->caractere); 
		pre_ordem(raiz->esquerda); 
		pre_ordem(raiz->direita); 
	}
}

void apagar_arvore(NO *raiz) { 
	if (raiz != NULL) { 
		apagar_arvore(raiz->esquerda); 
		apagar_arvore(raiz->direita); 
		free(raiz); 
	}
}