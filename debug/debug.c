#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// tree.h

// Definições
// Árvore de busca como lista ligada

typedef struct no NO;
typedef struct arvore ARVORE_PREFIXO;

struct no {

	char caractere;
	NO *esquerda;
	NO *direita;

};

struct arvore {

	NO *raiz;
	int total_nos;
	int bits;

};

// Funções de Árvore
// Inicialização
NO* cria_no() {
	NO *novo = (NO*)malloc(sizeof(NO));
	novo->esquerda = NULL;
	novo->direita = NULL;
	return (novo);
}

ARVORE_PREFIXO* cria_arvore() {
	ARVORE_PREFIXO *arvore = (ARVORE_PREFIXO*)malloc(sizeof(ARVORE_PREFIXO));
	arvore->raiz = cria_no();
	arvore->total_nos = 0;
	arvore->bits = 0;
	return (arvore);
}

// Funções de Árvore
// Busca
int busca(NO *raiz, int chave) {
	char resultado;
	
	if (raiz == NULL) {
		return -1;
	}
	
	resultado = raiz->caractere;
	if (resultado == chave) {
		return resultado;
	} else if (chave < resultado) {
		return busca(raiz->direita, chave);
	} else {
		return busca(raiz->esquerda, chave);
	}

}

// Número de Nós
int conta_nos(NO *raiz) {
	if (raiz == NULL) {
		return 0;
	} else {
		return 1 + conta_nos(raiz->esquerda) + conta_nos(raiz->direita);
	}
}

// Criar nó
NO* novo(char valor, NO* esquerda, NO* direita) { 
	NO *novo;
	novo = (NO*)malloc(sizeof(NO)); 
	novo->caractere = valor; 
	novo->esquerda = esquerda; 
	novo->direita = direita; 
	return novo; 
} 

// Inserção de nó
int insere(NO *raiz, char valor) {

	char aux;
	if (raiz == NULL) {
		return novo(valor, NULL, NULL);
	}

	aux = raiz->caractere;
	if (valor < aux) {
		raiz->esquerda = insere(raiz->esquerda, valor);
	} else {
		raiz->direita = insere(raiz->direita, valor);
	}

	return raiz;

}

// Percurso Pré-Ordem
void __pre_order(NO *raiz) {

	if(raiz != NULL) {
		printf("%c ", raiz->caractere);
		__pre_order(raiz->esquerda);
		__pre_order(raiz->direita);
	}
}

void pre_order(ARVORE_PREFIXO* arvore) {

	__pre_order(arvore->raiz);

}

// decode.h

// Funções de Árvore

// Adicionar nó recursivamente
// Parâmetros: nó de início, nó que será adicionado, esquerda ou direita


// Transformar entrada em árvore
ARVORE_PREFIXO* arvore_entrada(char *percurso);

// Funções de Descompressão
void descomprime(int* comprimida) {

	char *mensagem = NULL;
	int total_bits = 0;
	int bits_descomprimidos = 0;
	int total_caracteres = 0;
	double taxa_compressao = 0;

	total_caracteres = strlen(mensagem);

	// Cálculo da taxa de compressão
	bits_descomprimidos = sizeof(char) * total_caracteres;
	taxa_compressao = (double)total_bits/(double)bits_descomprimidos;
	taxa_compressao = taxa_compressao * 100;

	// Impressão dos dados
	printf("\tMENSAGEM DESCOMPRIMIDA\n");
	printf("\t%s\n", mensagem);
	printf("\tNúmero de bits\t= %d", total_bits);
	printf("\tNúmero de caracteres\t=  %d", total_caracteres);
	printf("\tTaxa de compressão\t= %lf", taxa_compressao);

}

// Tabela
void tabela() {
	printf("\tcaractere\tbits\tcodificação\n");
	printf("\t--------------------\n");
}


// leitura.h

// Funções de leitura de arquivo

void ler_arquivo();

// *** trocar scanf por fscanf *** 


// Funções de leitura dentro do arquivo
// Ler percurso pré-ordem da árvore
char* percurso() {
	char *percurso = NULL;
	char aux;
	int counter = 0;
	do {
		scanf("%c", &aux);
		percurso = (char*)realloc(percurso, sizeof(char*) * counter + 1);
		percurso[counter] = aux;
		counter++;
	} while (aux != 10);
	percurso[counter-1] = '\0'; // remover quebra de linha
	return percurso;
}
// Ler mensagem comprimida (bits)
int *comprimida() {
	int *comprimida = NULL;
	char aux;
	int counter = 0;
	do {
		scanf("%c", &aux);
		comprimida = (int*)realloc(comprimida, sizeof(int) * counter + 1);
		comprimida[counter] = aux;
		counter++;
	} while (aux != 10);
	return comprimida;
}

int main(int argc, char const *argv[]) {
	// Definições
	ARVORE_PREFIXO *arvore = NULL;
	NO *raiz = NULL;

	char *pre_ordem = NULL;
	int *codigo = NULL;

	printf("\tINICIALIZAÇÃO DA ÁRVORE\n");
	// Inicialização da Árvore
	arvore = cria_arvore();
	raiz = cria_no();
	arvore->raiz = raiz;

	printf("\tLER ENTRADA\n");
	// Entrada
	pre_ordem = percurso();
	codigo = comprimida();

	// Operações

	// Impressão

	return 0;

}