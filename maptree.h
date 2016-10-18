//
// Created by alvino on 15/10/16.
//

#ifndef STRING_MAPTREE_H
#define STRING_MAPTREE_H
#include "stringList.h"
#include "priorityQueue.h"
#include "hash_table.h"
#include "frequencyCounter.h"

Node_String* maptreeRepresetantion(Node* current, Node_String* representree, Node_String* binary_value, Hashtable *hashtree);
Hashtable* maptreeHashTable(Node* current, int binary_value, Hashtable *hashtree);

#endif //STRING_MAPTREE_H
