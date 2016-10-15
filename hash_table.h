//
// Created by alvino on 04/10/16.
//

#ifndef STRING_HASH_TABLE_H
#define STRING_HASH_TABLE_H

#include<stdio.h>
#include<stdlib.h>
#include "stringList.h"
#define MAX_HASH 5003

typedef struct element Element;

typedef struct hashTable Hashtable;

int hash_function(char key);

Hashtable* create_hash_table();

void put(Hashtable *ht, char key, Node_String* value);

int get(Hashtable *ht, char key);

void Remove(Hashtable *ht, char key);

int contains_key(Hashtable *ht, char key);

void print_hash_table(Hashtable *ht);

#endif //STRING_HASH_TABLE_H
