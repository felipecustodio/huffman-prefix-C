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
	printf("\tPRE-ORDEM: ");
	percurso = ler_string();
	printf("\n\t%s\n\n", percurso);

	printf("\tADICIONAR ENTRADA\n");
	adicionar_no(arvore, percurso, 0);

	pre_ordem(arvore);

	return 0;
}

