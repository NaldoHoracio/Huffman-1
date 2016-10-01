#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node Node;

Node* create_linked_list();

int is_empty(Node *first);

Node* insert_node(Node *first, char item);

void print_linked_list(Node *first);

Node* search_linked_list(Node *first, char item);

char find(Node *first, int position);

int size(Node *first);

char* c_str(Node *first, char *str);

Node* buildList(Node *first, char *str);
