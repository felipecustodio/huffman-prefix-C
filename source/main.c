#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "decode.h"
#include "leitura.h"

int main(int argc, char const *argv[]) {
	
	system("clear"); // Limpar terminal após compilação
	// Definições
	ARVORE_PREFIXO arvore;
	criar_no(&arvore);

	char *percurso = NULL;
	char *mensagem = NULL;
	
	// Leitura
	printf("\t./entradas/nome_do_arquivo.pre\n");
	ler_arquivo(&percurso, &mensagem);

	// Criar árvore a partir da entrada
	adicionar_no(&arvore, percurso, 0);

	// Decodificar alfabeto
	tabela();
	imprime_alfabeto(arvore, 0);

	// Descomprimir mensagem
	descomprime(arvore, mensagem); 

	// Liberar memória
	apagar_arvore(arvore);
	free(percurso);
	free(mensagem);

	return 0;
}