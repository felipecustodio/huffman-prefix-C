#ifndef __DECODE_H
#define __DECODE_H

// Alfabeto Decodificado

// Funções de Decodificação
 
// Transformar entrada em árvore
void arvore_entrada(ARVORE_PREFIXO* arvore, char *percurso, int inicio, int filho);
// Descompressão
void descomprime(char* comprimida);
// Auxiliar / Impressão
void tabela();

#endif