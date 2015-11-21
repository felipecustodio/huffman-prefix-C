#include <stdio.h>
#include <stdlib.h>

// Definições
// Árvore Binária
#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct no NO; 
typedef NO* ARVORE_PREFIXO; 

struct no { 
	char caractere;
	NO *esquerda; 
	NO *direita; 
};

void criar_no(NO **novo);
int adicionar_no(NO** inicio, char* percurso, int indice);
int no_externo(NO* teste);
void pre_ordem(NO *raiz);
void apagar_arvore(NO *raiz);