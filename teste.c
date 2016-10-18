//
// Created by edvonaldoh on 17/10/16.
//
//
// Created by edvonaldoh on 15/10/16.
//
#ifndef STRING_HEADER_H
#define STRING_HEADER_H

#include "frequencyCounter.h"
#include "frequencyCounter.c"
#include "hash_table.h"
#include "hash_table.c"
#include "helpful.h"
#include "helpful.c"
#include "helpful_function.h"
#include "helpful_function.c"
#include "maptree.h"
#include "maptree.c"
#include "priorityQueue.h"
#include "priorityQueue.c"
#include "stringList.h"
#include "stringList.c"
#include "bitVector.h"
#include "bitVector.c"

void compress(char * intput, char * output)
{

}
void decompress(char * intput)
{

}

int main()
{
    FILE * pFile;
    long size;

    pFile = fopen ("teste.txt","rb");
    if (pFile==NULL) perror ("Error opening file");
    else
    {
        fseek (pFile, 0, SEEK_END);   // non-portable
        size=ftell (pFile);
        fclose (pFile);
        printf ("Size of myfile.txt: %ld bytes.\n",size);
    }

    return 0;
}

#endif //STRING_HEADER_H
