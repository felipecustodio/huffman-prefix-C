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

// Funções de Árvore

// Busca
int busca(NO *raiz, int chave) {
	char resultado;
	
	if (raiz == NULL) {
		return -1;
	}
	
	resultado = raiz->caractere;
	if (resultado == chave) {
		return resultado;
	} else if (chave < resultado) {
		return busca(raiz->proximo, chave);
	} else {
		return busca(raiz->anterior, chave);
	}

}

// Número de Nós
int conta_nos(NO *raiz) {
	if (raiz == NULL) {
		return 0;
	} else {
		return 1 + conta_nos(raiz->anterior) + conta_nos(raiz->proximo);
	}
}

// Inserção

NO* novo(char valor, NO* esquerda, NO* direita) { 
/* cria novo nó com info x e links left e right */ 
	NO *novo;
	novo = (NO*)malloc(sizeof(NO)); 
	novo->caractere = valor; 
	novo->anterior = esquerda; 
	novo->proximo = direita; 
	return novo; 
} 

int insere(NO *raiz, char valor) {

	char aux;
	if (raiz == NULL) {
		return novo(valor, NULL, NULL);
	}

	aux = raiz->caractere;
	if (valor < aux) {
		raiz->anterior = insere(raiz->anterior, valor);
	} else {
		raiz->proximo = insere(raiz->proximo, valor);
	}

	return raiz;

}