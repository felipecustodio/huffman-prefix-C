#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "decode.h"
#include "leitura.h"

int main(int argc, char const *argv[]) {
	
	// Definições
	ARVORE_PREFIXO *arvore = NULL;
	NO *raiz = NULL;

	char *percurso = NULL;
	int *codigo = NULL;

	// Inicialização da Árvore
	arvore = cria_arvore();
	raiz = cria_no();
	arvore->raiz = raiz;

	// Entrada

	// Operações de Decodificação

	return 0;
}

