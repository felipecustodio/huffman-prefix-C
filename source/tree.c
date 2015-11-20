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

// **************
int adicionar_no(NO *inicio, char* percurso, int indice) {

	printf("\tChamada de adicionar_no\n");
	printf("\tPERCURSO[%d] = %c\n", indice, percurso[indice]);
	if(inicio->esquerda == NULL) {
		printf("\tInserindo à esquerda...\n");
		inicio->esquerda = inserir_filho(FILHO_ESQ, inicio, percurso[indice]);
	} else {
		printf("\tInserindo à direita...\n");
		inicio->direita = inserir_filho(FILHO_DIR, inicio, percurso[indice]);
	}

	if(percurso[indice] == '*') {
		printf("\tChamando recursão para esquerda\n");
		adicionar_no(inicio->esquerda, percurso, indice + 1);
		printf("\tChamando recursão para direita\n");
		adicionar_no(inicio->direita, percurso, indice + 1);
	} else {
		printf("\tCaractere inserido, retornando\n");
		return (1);
	}
}

int no_externo(NO* teste) {
	if(teste->esquerda == NULL && teste->direita == NULL) {
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