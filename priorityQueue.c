//
// Created by alvino on 03/10/16.
//
#ifndef PRIORITY_QUEUE_C
#define PRIORITY_QUEUE_C

#include "priorityQueue.h"

Node* createPriorityQueue(){ //cria a fila de prioridade
    return NULL;
}

int isEmpty(Node *node){ // verifica se o nó está vazio
    return ((node == NULL) ? 1 : 0);
}
void printPriorityQueue(Node *node){ //imprimindo a fila de prioridade
    Node *p_aux; // ponteiro auxiliar que aponta para o tipo Node
    if(node == NULL)
        printf("\nEmpty Priority Queue.\n"); // caso a fila esteja vazia, imprime informativo
    for(p_aux = node; p_aux != NULL; p_aux = p_aux->Next){ //percorrendo a lista
        printf("Character: %c -- Frequency: %d  ---> \n", p_aux->n_character, p_aux->n_frequency); //imprimindo o caractere e sua frequencia
    }
}

Node* insert(Node *node, unsigned char character, int frequency){ // funçao para inserir na lista
    if((node == NULL) || (frequency <= node->n_frequency)){ // checkando se vai inserir no inicio
        Node *newNode = (Node*) malloc(sizeof(Node)); // alocando espaço pra um tipo Node
        newNode->n_character = character; // adicionando o caractere
        newNode->n_frequency = frequency; // adicionando a frequencia
        newNode->p_left = NULL; // setando null no ponteiro da arvore esquerda
        newNode->p_right = NULL; // setando null no ponteiro da arvore direita
        newNode->Next = node; // apontando newNode pra o primeiro elemento da lista
        Node_String *newNode_String = (Node_String*) malloc(sizeof(Node_String*));// allocando espaço pra um tipo Node_String
        //printf("\nInsert: %c -- Frequency: %d\n", character, frequency); // imprimindo o elemento inserido e sua frequencia
        return newNode;
    }
    else{
        Node *p_aux = node; // p_aux ponta para o começo da lista
        Node *newNode = (Node*) malloc(sizeof(Node)); // alocando memoria para um novo Node
        while(p_aux->Next != NULL && frequency > p_aux->Next->n_frequency){ // percorrendo a lista até encontrar o lugar para inserir ordenado
            p_aux = p_aux->Next;
        }
        newNode->Next = p_aux->Next; // novo nó vai apontar para o mesmo lugar de p_aux->next
        newNode->n_character = character; // atribuindo o caractere para o novo nó
        newNode->n_frequency = frequency; // atribuindo a frequencia para o novo nó
        newNode->p_left = NULL; // setando os ponteiros da arvore para NULL
        newNode->p_right = NULL; // setando os ponteiros da arvore para NULL
        p_aux->Next = newNode;
        Node_String *newNode_String = (Node_String*) malloc(sizeof(Node_String*)); // allocando espaço pra um tipo Node_String
        //printf("\nInsert: %c -- Frequency: %d\n", character, frequency);
        return node;
    }
}

Node *insertTreeNode(Node *node, Node *queueNode){    //	queue = insertTreeNode(queue, newNode);
    if(node == queueNode){
        queueNode->Next = NULL;
        return queueNode;
    }
    else if((node == NULL) || (queueNode->n_frequency <= node->n_frequency)){
        queueNode->Next = node;
        return queueNode;
    }
    else{
        Node *p_aux = node;
        while(p_aux->Next != NULL && queueNode->n_frequency > p_aux->Next->n_frequency){
            p_aux = p_aux->Next;
        }
        queueNode->Next = p_aux->Next;
        p_aux->Next = queueNode;
        return node;
    }
}

#endif// PRIORITY_QUEUE_C

