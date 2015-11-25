#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "decode.h"

// Função auxiliar para concatenar string e caractere
char *concatenar(char *codigo, char novo) {
	size_t tamanho = strlen(codigo);
    char *novo_codigo = (char*)malloc(tamanho + 2); // 2 novos espaços: [ novo ] [ /0 ]
	strcpy(novo_codigo, codigo);
	novo_codigo[tamanho] = novo;
	novo_codigo[tamanho + 1] = '\0';
	return novo_codigo;
}

// Imprime cabeçalho
void tabela() {
	printf("\n\tcaractere bits codificação\n");
	printf("\t--------------------------\n");
}

// Imprimir alfabeto em pré-ordem
void dicionario(NO *raiz, char *codigo) {
	
	// Impressão do caractere, número de bits e seu código na árvore
	if (raiz != NULL) {
		if (raiz->caractere != '*') {
			printf("\t%c\t%d\t%s\n", raiz->caractere, strlen(codigo), codigo);
		}
		// Chamadas de pré-ordem
		dicionario(raiz->esquerda, concatenar(codigo, '0')); 
		dicionario(raiz->direita, concatenar(codigo, '1')); 
	}
}

// Funções de Descompressão
void descomprime(ARVORE_PREFIXO arvore, char* comprimida) {

	char *descomprimida = NULL;
	int total_bits = 0;
	int bits_descomprimidos = 0;
	int total_caracteres = 0;
	double taxa_compressao = 0;

	// Algoritmo de descompressão da mensagem
	NO *atual = arvore;
	int i = 0;
	char bit;
	// Percorrer a mensagem comprimida
	while(i < strlen(comprimida)) {
		// Alcançar nó externo da árvore
		while(!(no_externo(atual))) {
			bit = comprimida[i];
			// 0 - Vá para a esquerda
			if (bit == '0') {
				atual = atual->esquerda;
				i++;
			// 1 - Vá para a direita
			} else if (bit == '1') {
				atual = atual->direita;
				i++;
			}
		}
		// Inserir caractere do nó externo na mensagem descomprimida
		descomprimida = (char*)realloc(descomprimida, sizeof(char) * total_caracteres + 1);
		descomprimida[total_caracteres] = atual->caractere;
		total_caracteres++;
		// Resetar nó auxiliar para a raiz
		atual = arvore;

	}

	// Transformar mensagem descomprimida em string
	descomprimida[total_caracteres] = '\0';

	// Cálculo da taxa de compressão
	total_bits = total_caracteres * 8;
	bits_descomprimidos = sizeof(char) * strlen(comprimida);
	taxa_compressao = (double)bits_descomprimidos/(double)total_bits;
	taxa_compressao = taxa_compressao * 100;

	// Impressão dos dados
	printf("\n\t%s\n", descomprimida);
	printf("\tNúmero de bits = %d\n", bits_descomprimidos);
	printf("\tNúmero de caracteres = %d\n", total_caracteres);
	printf("\tTaxa de compressão = %lf%%\n\n", taxa_compressao);
	
	free(descomprimida);
	
}