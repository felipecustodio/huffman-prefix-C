/*----------------------------------------------------
ICMC - USP
BCC - 2015
SCC0202 - Algoritmos e Estruturas de Dados I

           \/ |    |/
        \/ / \||/  /_/___/_
         \/   |/ \/
    _\__\_\   |  /_____/_
           \  | /          /
  __ _-----`  |{,-----------~
            \ }{
             }{{
             }}{
             {{}
       , -=-~{ .-^- _
             `}
              {

Projeto 03 - Código Prefixo

Alunos	:	Felipe Scrochio Custodio	9442688
			Danilo de Moraes Costa		8921972

Programa compilado/testado em ambiente Linux

Opções:
    a) Executar 'make' na pasta principal para compilar e rodar
    b) Executar 'make run' na pasta principal apenas para rodar

------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "decode.h"
#include "leitura.h"

int main(int argc, char const *argv[]) {	
	
	// Para Windows: 
	// system("cls");
	system("clear"); // Limpar terminal após compilação

	// Definições
	ARVORE_PREFIXO arvore = NULL;
	char *percurso = NULL;
	char *mensagem = NULL;
	char *codigo = NULL;
	
	// Leitura
	printf("\n\tPROJETO 03 - CÓDIGO PREFIXO\n\n");
	printf("\t./entradas/nome_do_arquivo.pre\n");
	ler_arquivo(&percurso, &mensagem);

	// Criar árvore a partir da entrada
	adicionar_no(&arvore, percurso);
	
	// Decodificar alfabeto
	tabela();
	// Código inicial para algoritmo de concatenar
	codigo = (char*)malloc(sizeof(char) * 2);
	codigo[0] = '0';
	codigo[1] = '\0';
	// Primeira chamada para percorrer árvore
	dicionario(arvore, codigo);

	// Descomprimir mensagem
	descomprime(arvore, mensagem); 

	// Liberar memória
	apagar_arvore(arvore);
	free(percurso);
	free(mensagem);

	return 0;
}