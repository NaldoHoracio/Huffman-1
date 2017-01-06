//
// Created by alvino on 18/10/16.
//

#ifndef STRING_REBUILDTREE_H
#define STRING_REBUILDTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "helpful.h"
//#include "helpful.c"
//#include "stringList.c"
#include "stringList.h"
#include "priorityQueue.h"
//#include "priorityQueue.c"

typedef struct Node Node;

Node* create_node_rebuild_tree(char n_character, Node *p_left, Node *p_right);

Node* rebuild_tree(Node_String* representree);

#endif //STRING_REBUILDTREE_H
