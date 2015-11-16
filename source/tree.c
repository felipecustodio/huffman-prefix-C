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

// Criar nó
NO* novo(char valor, NO* esquerda, NO* direita) { 
	NO *novo;
	novo = (NO*)malloc(sizeof(NO)); 
	novo->caractere = valor; 
	novo->anterior = esquerda; 
	novo->proximo = direita; 
	return novo; 
} 

// Inserção de nó
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

// Percurso Pré-Ordem
void __pre_order(NO *raiz) {

	if(raiz != NULL) {
		printNode(raiz);
		__pre_order(raiz->esquerda);
		__pre_order(raiz->direita);
	}
}

void pre_order(ARVORE_PREFIXO* arvore) {

	__pre_order(arvore->raiz);

}