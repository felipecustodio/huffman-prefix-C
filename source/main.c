#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "decode.h"
#include "leitura.h"

int main(int argc, char const *argv[]) {
	
	// Definições
	ARVORE_PREFIXO arvore;
	arvore = criar_arvore();

	printf("\t1-INSERE 2-IMPRIME 0-SAI\n");
	int menu = 4;
	char aux;
	while (menu != 0) {
		printf("\t");
		scanf("%d", &menu);
		switch(menu) {
			case 1:
				printf("\tDIGITE O CARACTERE A SER INSERIDO: ");
				scanf("%c", &aux);
				getchar();

				break;
			case 2:
				printf("\t");
				pre_ordem(arvore);
				break;
		}
	}

	return 0;
}

