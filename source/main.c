#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "decode.h"
#include "leitura.h"

int main(int argc, char const *argv[]) {
	
	// Definições
	ARVORE_PREFIXO arvore;
	arvore = criar_arvore();

	char *percurso = NULL;
	char *mensagem = NULL;
	
	// Leitura
	ler_arquivo(&percurso, &mensagem);
	printf("\t%s\n\t%s\n", percurso, mensagem);

	// Criar árvore a partir da entrada
	adicionar_no(arvore, percurso, 0);

	// Decodificar mensagem

	pre_ordem(arvore);

	return 0;
}