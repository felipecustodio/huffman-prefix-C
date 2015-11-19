#ifndef __DECODE_H
#define __DECODE_H

#include "tree.h"

// Funções de Decodificação
 
// Transformar entrada em árvore
ARVORE_PREFIXO* arvore_entrada(char *percurso);
// Descompressão
void descomprime();
// Auxiliar / Impressão
void tabela();

#endif