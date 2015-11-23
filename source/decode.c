#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"
#include "decode.h"

// Função auxiliar para concatenar codificação do alfabeto
unsigned concatenar(unsigned x, unsigned y) {
    unsigned potencia = 10;
    while(y >= potencia) {
        potencia *= 10;
    }
    return (x * potencia + y);        
}

// Calcular tamanho em bits do código de um caractere
double bits(int codigo) {
	double tamanho;
	if(codigo == 0) {
		tamanho = 1;
	} else {
		tamanho = floor(log10(abs(codigo))) + 1;
	}
	return (tamanho);
}

// Tabela
void tabela() {
	printf("\tcaractere bits codificação\n");
	printf("\t--------------------------\n");
}

// Imprimir alfabeto em pré-ordem
void imprime_alfabeto(NO *raiz, int codigo) {
	
	// Impressão do caractere, número de bits e seu código na árvore
	if (raiz != NULL) {
		if (raiz->caractere != '*') {
			printf("\t%c\t%.0lf\t%d\n", raiz->caractere, bits(codigo), codigo);
		}
		// Chamadas de pré-ordem
		imprime_alfabeto(raiz->esquerda, concatenar(codigo, 0)); 
		imprime_alfabeto(raiz->direita, concatenar(codigo, 1)); 
	}
}

// Funções de Descompressão
void descomprime(ARVORE_PREFIXO arvore, char* comprimida) {

	char *descomprimida = NULL;
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

	NO *atual = arvore;
	int i = 0;
	char bit;
	while(i < strlen(comprimida)) {
		while(!(no_externo(atual))) {
			bit = comprimida[i];
			if (bit == '0') {
				atual = atual->esquerda;
				i++;
			} else if (bit == '1') {
				atual = atual->direita;
				i++;
			}
		}
		descomprimida = (char*)realloc(descomprimida, sizeof(char) * total_caracteres + 1);
		descomprimida[total_caracteres] = atual->caractere;
		total_caracteres++;
		atual = arvore;
	}

	descomprimida[total_caracteres] = '\0';

	// Cálculo da taxa de compressão
	// total_caracteres = strlen(descomprimida);
	total_bits = total_caracteres * 8;
	bits_descomprimidos = sizeof(char) * total_caracteres;
	taxa_compressao = (double)total_bits/(double)bits_descomprimidos;
	taxa_compressao = taxa_compressao * 100;

	// Impressão dos dados
	printf("\tMENSAGEM DESCOMPRIMIDA\n");
	printf("\t%s\n", descomprimida);
	printf("\tNúmero de bits = %d\n", bits_descomprimidos);
	printf("\tNúmero de caracteres = %d\n", total_caracteres);
	printf("\tTaxa de compressão = %lf%%\n", taxa_compressao);
	free(descomprimida);
	
}