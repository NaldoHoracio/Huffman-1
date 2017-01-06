//
// Created by pablo on 16/10/16.
//
#ifndef HELPFUL_C
#define HELPFUL_C

#include "helpful.h"

Node* create_empty_tree() { //criando uma arvore vazia
    return NULL;
}

void printPreOrder(Node *bt){ //funçao para imprimir a arvore em pre ordem
    if(!isEmpty(bt)){ //enquanto for diferente de vazio, imprime em pre ordem, recursivamente
        printf("Character: %c -- Frequency: %d\n", bt->n_character, bt->n_frequency);
        printPreOrder(bt->p_left); //chamando recursivamente para a arvore da esquerda
        printPreOrder(bt->p_right); // chamando recursivamente para a arvore da direita
    }
}

Node* buildTree(Node *list){ //funcao para converter a lista em árvore, imprimindo o estado atual
    /* merge enquanto lista possuir elemento */
    while(list->Next != NULL){
        list = merge(list); //chamando a funçao merge para lista
        //printf("\nEstado atual da lista:\n");
        //printPriorityQueue(list); // imprimindo o estado da lista para cada iteracao
    }
    return list;
}

Node* merge(Node* queue){ // funçao de merge nos nós da lista
    /* estabelecendo definições para o novo nó criado */
    Node *newNode = (Node*) malloc(sizeof(Node)); //alocando memoria para o node
    newNode->p_left = queue; // recebe o primeiro nó da lista
    newNode->p_right = queue->Next; // recebe o segundo nó da lista

    /* após retirada dos 2 primeiros elementos, queue aponta para o terceiro */
    if(newNode->p_right->Next != NULL)
        queue = newNode->p_right->Next;
    else
        queue = newNode;

    newNode->p_left->Next = NULL; //setando null para p_left do novo nó
    newNode->p_right->Next = NULL; //setando null para p_right do novo nó
    newNode->n_character = '*'; // adicionando o caractere identificador '*'
    /* nó pai recebe a soma da frequencia dos filhos */
    newNode->n_frequency = newNode->p_left->n_frequency + newNode->p_right->n_frequency;

    /*inserindo novamente na fila, já */
    queue = insertTreeNode(queue, newNode);

    return queue;
}

#endif// HELPFUL_C
