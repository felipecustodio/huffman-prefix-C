#ifndef __DECODE_H
#define __DECODE_H

// Inserir caractere em string
char *concatenar(char *codigo, char novo);
// Alfabeto
void dicionario(NO *raiz, char *codigo);
// Descompressão
void descomprime(ARVORE_PREFIXO arvore, char* comprimida);
// Auxiliar / Impressão
void tabela();

#endif