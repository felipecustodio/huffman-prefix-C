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

NO* criar_arvore(void);
NO* inserir_filho(int filho, NO *no, char valor);
int adicionar_no(NO *inicio, char* percurso, int indice);
void pre_ordem(NO *raiz);
void apagar_arvore(NO *raiz);