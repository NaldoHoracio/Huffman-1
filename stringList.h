
//
// Created by alvino on 01/10/16.
//

#ifndef STRING_STRINGLIST_H
#define STRING_STRINGLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_string Node_String;

Node_String* create_linked_list();

int is_empty(Node_String *first);

Node_String* insert_node(Node_String *first, char item);

void print_linked_list(Node_String *first);

Node_String* search_linked_list(Node_String *first, char item);

char find(Node_String *first, int position);

int size(Node_String *first);

char* c_str(Node_String *first, char *str);

Node_String* buildList(Node_String *first, char *str);
#endif //STRING_STRINGLIST_H
