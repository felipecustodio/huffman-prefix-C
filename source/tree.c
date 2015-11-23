#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

void criar_no(NO **novo) { 
	(*novo) = (NO*)malloc(sizeof(NO)); 
	if ((*novo) != NULL) { 
		(*novo)->esquerda = NULL; 
		(*novo)->direita = NULL; 
	} 
}

// transformar entrada em arvore
int adicionar_no(NO **inicio, char *percurso, int indice) {

	int aux; // controlador do índice dentro das chamadas recursivas
	if((*inicio) == NULL) {
		(*inicio) = (NO*)malloc(sizeof(NO));
		(*inicio)->direita = NULL;
		(*inicio)->esquerda = NULL;
		(*inicio)->caractere = percurso[indice]; 
	} else {
		(*inicio)->caractere = percurso[indice];
	}

	if(percurso[indice] == '*') {
		aux = adicionar_no(&((*inicio)->esquerda), percurso, ++indice);
		adicionar_no(&((*inicio)->direita), percurso, ++aux);
	} else {
		return (indice);
	}
}

int no_externo(NO *teste) {
	if((teste != NULL) && (teste->esquerda == NULL) && (teste->direita == NULL)) {
		return (1);
	} else {
		return (0);
	}
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