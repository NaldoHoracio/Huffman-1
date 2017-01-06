//
// Created by alvino on 04/10/16.
//
/*
 * ifndef, define, include - evitar problemas em arquivos incluídos mais de uma vez
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<stdio.h>
#include<stdlib.h>
#include "stringList.h"

#define SIZE_HASH 256

typedef struct element Element;

typedef struct hashTable Hashtable;

int hash_function(char key);

Hashtable* create_hash_table();

Hashtable* put(Hashtable *ht, char key, Node_String* value);

Hashtable* putI(Hashtable *ht, char key, long int value);

Node_String* get(Hashtable *ht, char key);

long int getI(Hashtable *ht, char key);

void Remove(Hashtable *ht, char key);

int contains_key(Hashtable *ht, char key);

void print_hash_table(Hashtable *ht);

#endif //HASH_TABLE_H
