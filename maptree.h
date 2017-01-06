//
// Created by alvino on 15/10/16.
//

#ifndef STRING_MAPTREE_H
#define STRING_MAPTREE_H

#include <stdio.h>
#include "frequencyCounter.h"
#include "priorityQueue.h"
#include "hash_table.h"
#include "stringList.h"

Node_String* maptreeRepresetantion(Node* current, Node_String* representree, Node_String* binary_value, Hashtable *hashtree);

Hashtable* maptreeHashTable(Node* current, long int binary_value, Hashtable *hashtree);

int getTrash(FILE* file);

int getSizeTree(FILE* file);

Node_String* getTree_Representation(FILE* file, Node_String* tree, int sizeTree, int sizeName);

int sizeBytes(FILE* file);

int getSizeName(FILE* file);

Node_String* getName(FILE* file, Node_String* tree, int sizeTree);

#endif //STRING_MAPTREE_H
