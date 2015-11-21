#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "decode.h"

// Tabela
void tabela() {
	printf("\tcaractere\tbits\tcodificação\n");
	printf("\t--------------------\n");
	//imprime_alfabeto();
}

void imprime_alfabeto();

// Funções de Descompressão
void descomprime(char* comprimida) {

	char *mensagem = NULL;
	int total_bits = 0;
	int bits_descomprimidos = 0;
	int total_caracteres = 0;
	double taxa_compressao = 0;

	/*
	Comece pela raiz da árvore. 
	 Repita até alcançar um nó externo da árvore: 
		o Leia um bit da mensagem. 
		o Vá pela aresta da esquerda se o bit for 0; vá pela aresta da direita se for 1. 
	 Imprima o caractere que está no nó externo. 
	*/


	// Cálculo da taxa de compressão
	total_caracteres = strlen(mensagem);
	bits_descomprimidos = sizeof(char) * total_caracteres;
	taxa_compressao = (double)total_bits/(double)bits_descomprimidos;
	taxa_compressao = taxa_compressao * 100;

	// Impressão dos dados
	printf("\tMENSAGEM DESCOMPRIMIDA\n");
	printf("\t%s\n", mensagem);
	printf("\tNúmero de bits\t= %d", total_bits);
	printf("\tNúmero de caracteres\t=  %d", total_caracteres);
	printf("\tTaxa de compressão\t= %lf%%", taxa_compressao);

}