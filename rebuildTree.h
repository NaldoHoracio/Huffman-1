//
// Created by alvino on 18/10/16.
//

#ifndef STRING_REBUILDTREE_H
#define STRING_REBUILDTREE_H

#include "stringList.h"

typedef struct Node Node;

Node* create_node_rebuild_tree(char n_character, Node *p_left, Node *p_right);

Node* rebuild_tree(Node_String* representree);

#endif //STRING_REBUILDTREE_H
