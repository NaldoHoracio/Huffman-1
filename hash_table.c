#ifndef HASH_TABLE_C
#define HASH_TABLE_C

#include "hash_table.h"

struct element
{
    char key;
    Node_String* value;
    long int value_i;
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

Hashtable* put(Hashtable *ht, char key, Node_String* value)
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
    return ht;
}
Hashtable* putI(Hashtable *ht, char key, long int value)
{

        int h;
        h = h % SIZE_HASH;
        while (ht->table[h] != NULL)
        {
            if (ht->table[h]->key == key)
            {
                ht->table[h]->value_i = value;
                break;
            }
            h = (h + 1) % 256;
        }
        if (ht->table[h] == NULL)
        {
            Element *new_element = (Element*) malloc(sizeof(Element));
            new_element->key = key;
            new_element->value_i = value;
            ht->table[h] = new_element;
        }
        return ht;
}


Node_String* get(Hashtable *ht, char key)
{
    int h;
    h = h % SIZE_HASH;
    while (ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            return ht->table[h]->value;
        }

        h = (h + 1) % 256;
    }
    printf("HashTable  is Empty!\n");
    return NULL;
}

long int getI(Hashtable *ht, char key)
{
    int h=0;
    h = h % SIZE_HASH;
    while (ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            return ht->table[h]->value_i;
        }

        h = (h + 1) % 256;
    }
    printf("HashTable is Empty for key (%c)! \n", key);
    return 0;
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

void print_hash_table(Hashtable *ht)
{
    int h;
    h = h%SIZE_HASH;
    while (ht->table[h] != NULL)
    {
        //ht->table[h]->value;
        printf("%c -->", ht->table[h]->key);
        print_linked_list(ht->table[h]->value);
        h = (h+1)%SIZE_HASH;
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

#endif// HASH_TABLE_C
