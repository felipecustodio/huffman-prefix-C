#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "decode.h"

// Funções de Entrada

// Transformar entrada em árvore (protótipo inicial, fazer teste de mesa)
// Testar em mesa a função insere() da árvore

// Funções do alfabeto codificado

// Percorrer árvore decodificando o alfabeto
// TAD alfabeto maybe?

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

	// Percorrer mensagem (passar tamanho de 'comprimida' como parametro?)
	// Utilizar o alfabeto criado

	// Cálculo da taxa de compressão
	total_caracteres = strlen(mensagem); // conferir se strlen trata o \0 no final
	bits_descomprimidos = sizeof(char) * total_caracteres;
	taxa_compressao = (double)total_bits/(double)bits_descomprimidos;
	taxa_compressao = taxa_compressao * 100;

	// Impressão dos dados (fazer função separada)
	printf("\tMENSAGEM DESCOMPRIMIDA\n");
	printf("\t%s\n", mensagem);
	printf("\tNúmero de bits\t= %d", total_bits);
	printf("\tNúmero de caracteres\t=  %d", total_caracteres);
	printf("\tTaxa de compressão\t= %lf%%", taxa_compressao);

}