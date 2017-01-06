//
// Created by alvino on 03/10/16.
//

#ifndef STRING_PRIORITYQUEUE_H
#define STRING_PRIORITYQUEUE_H

#include <stdlib.h>
#include "frequencyCounter.h"
#include "stringList.h"

/* Definindo a estrutura Node */
typedef struct Node Node;

struct Node{
    unsigned char n_character; // guardará o caractere
    int n_frequency;  // guardará a frequencia do caractere
    Node *Next; // ponteiro apontando para proximo
    Node *p_left; // ponteiro esquerdo da árvore
    Node *p_right; //ponteiro direito da árvore
    Node_String *p_binary_value; //ponteiro tipo stringList que armazena uma lista de char (valor binario)
    char* s_binary_value;
};

Node* createPriorityQueue(); // cria uma fila de prioridade

int isEmpty(Node *node); // verifica se o nó está vazio

void printPriorityQueue(Node *node); // imprime a fila de prioridade

/* Insere um Node na piorityQueue */
Node* insert(Node *node, unsigned char character, int frequency);

/* Insere o nó com merge na PiorityQueue */
Node *insertTreeNode(Node *queue, Node *queueNode);

#endif //STRING_PRIORITYQUEUE_H
