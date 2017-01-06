//
// Created by alvino on 18/10/16.
//
#ifndef REBUILDTREE_C
#define REBUILDTREE_C

#include "rebuildTree.h"

// Criando novo nó da árvore e inserindo até formar a árvore
Node* create_node_rebuild_tree(char n_character, Node *p_left, Node *p_right)
{
    Node *new_node_tree = (Node*) malloc(sizeof(Node));
    new_node_tree->n_character = n_character;
    new_node_tree->p_left = p_left;
    new_node_tree->p_right = p_right;
    return new_node_tree;
}

int position=0;
Node* rebuild_tree(Node_String* representree)
{
    //printf("%d\n", position);
    if(position < size(representree)) {
        if (find(representree, position) == '*') {
            position = position + 1;
            Node *p_left = rebuild_tree(representree);
            position = position + 1;
            return create_node_rebuild_tree('*', p_left, rebuild_tree(representree));
        } else if (find(representree, position) == '!') {
            position = position + 1;
            return create_node_rebuild_tree(find(representree, position), NULL, NULL);
        }
        return create_node_rebuild_tree(find(representree, position), NULL, NULL);
    }
    else return NULL;
}
/*
int main()
{
    Node_String* representree = create_linked_list();
    int y=0;
    char x;
    char *n;
    puts("Digite os elementos da lista: ");
    scanf("%c", &x);
    while( y!=9)
    {
        representree = insert_node(representree, x);
        puts("Digite outro elemento para adicionar na lista:");
        scanf("%c", &x);
        y++;
    }

    //rebuild_tree(representree, y=0);
    printPreOrder(rebuild_tree(representree));

    return 0;
}
 */

#endif// REBUILD_TREE_C
