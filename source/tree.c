#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Funções de Árvore

// Inicialização

NO* cria_no() {
	NO *novo = (NO*)malloc(sizeof(NO));
	novo->esquerda = NULL;
	novo->direita = NULL;
	return (novo);
}

ARVORE_PREFIXO* cria_arvore() {
	ARVORE_PREFIXO *arvore = (ARVORE_PREFIXO*)malloc(sizeof(ARVORE_PREFIXO));
	arvore->raiz = cria_no();
	arvore->total_nos = 0;
	arvore->bits = 0;
	return (arvore);
}