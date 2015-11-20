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
	
	ler_arquivo(&percurso, &mensagem);
	printf("\t%s\n\t%s\n", percurso, mensagem);

	adicionar_no(arvore, percurso, 0);

	pre_ordem(arvore);

	return 0;
}

