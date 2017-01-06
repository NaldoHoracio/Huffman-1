//
// Created by pablo on 16/10/16.
//

#ifndef STRING_HELPFUL_H
#define STRING_HELPFUL_H

#include "priorityQueue.h"

/*criando uma arvore vazia */
Node* create_empty_tree();
/*imprimir a arvore em pre ordem */
void printPreOrder(Node *bt);
/* Converte a lista em árvore chamando sucessivos merges */
Node *buildTree(Node *list);
/* Merge de 2 nodes da fila
   Adicionando pai '*', e devolvendo para a fila */
Node *merge(Node* queue);

#endif //STRING_HELPFUL_H
