#include "hash_table.h"
#include "stringList.h"
#define SIZE_HASH 256

struct element
{
    char key;
    Node_String* value;
};

struct hashTable
{
    Element *table[256];
};

Hashtable* create_hash_table()
{
    Hashtable *ht =	(Hashtable*)malloc(sizeof(Hashtable));
    int i;
    for (i = 0; i < 256; i++)
    {
        ht->table[i] = NULL;
    }
    return ht;
}

void put(Hashtable *ht, char key, Node_String* value)
{
    int h;
    h = h % SIZE_HASH;
    while (ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            ht->table[h]->value = value;
            break;
        }
        h = (h + 1) % 256;
    }
    if (ht->table[h] == NULL)
    {
        Element *new_element = (Element*) malloc(sizeof(Element));
        new_element->key = key;
        new_element->value = value;
        ht->table[h] = new_element;
    }
}

char* get(Hashtable *ht, char key)
{
    int h;
    h = h % SIZE_HASH;
    while (ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            return (char*) (ht->table[h]->value);
        }

        h = (h + 1) % 256;
    }
    return (char*) -100;
}

void Remove(Hashtable *ht, char key)
{
    int h;
    h = h % SIZE_HASH;

    while (ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            ht->table[h] = NULL;
            ht->table[h]->key = -1;
        }
        h = (h+1)%256;
    }
}
/*
int main()
{
    Hashtable *ht = create_hash_table();
    put(ht, 3, 1000);
    put(ht, 14, 2000);
    put(ht, 15, 3000);
    put(ht, 92, 4000);

    return 0;
}

//
// Created by alvino on 04/10/16.
//
*/
