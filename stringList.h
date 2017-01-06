//
// Created by alvino on 01/10/16.
//

#ifndef STRING_LIST_H
#define STRING_LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_string Node_String;// define um nó

struct node_string  // define um nó
{
    char item; // contendo um caracter
    struct node_string *next_node; //um ponteiro pro proximo nó
};

Node_String* create_linked_list(); //cria uma lista vazia

int is_empty(Node_String *first); // verifica se a lista está vazia

Node_String* insert_node(Node_String *first, char item); //insere um nó no final da lista (string dinamica)

void print_linked_list(Node_String *first); //imprime a string

Node_String* search_linked_list(Node_String *first, char item); //função de procura por um item

char find(Node_String *first, int position); //função de procura através do indice do "vetor" (tal qual um "acesso direto")

int size(Node_String *first); //retorna o tamanho da lista (string)

char* c_str(Node_String *first, char *str); //transforma a string dinamica (lista) em um vetor de char

Node_String* insert_Node_String(Node_String *first, Node_String *String); //insere uma string no final da lista (string dinamica)

Node_String* buildList(Node_String *first, char *str);

Node_String* removeLast(Node_String* first);

Node_String* pop (Node_String* first);

Node_String* decToBin(int num, Node_String* str, int idx);

#endif //STRING_LIST_H
