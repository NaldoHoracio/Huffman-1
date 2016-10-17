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

void compress(char * intput, char * output)
{

}
void decompress(char * intput)
{

}

int main()
{
    FILE *file;
    char name_file[100];
    int op;// Operador para escolher a opcao desejada
    printf("Digite o que você deseja fazer: ");
    printf("1 - Compressão\n2 - Descompressão\n");
    scanf("%d", &op);

    if(op == 1)// Opção compressão
    {
        counter(name_file); // Lê e conta a frequencia
        Node *pq = createPriorityQueue();// Criando uma fila
        Hashtable *ht = create_hash_table();// Criando a hash
        pq = buildTree(pq);// Montando a arvore de Huffman
        //Hashtable* hashtree = create_hash_table(); // criando a hash que receberá as chaves e valores das folhas da árvore
        Node_String* representree = create_linked_list(); // criando a lista encadeada representação da árvore
        Node_String* binary_value = create_linked_list(); //criando a lista encadeada binary_value

    }
    else if(op == 2)// Opção descompressão
    {
        printf("Descompressão\n");
    }
    else
    {
        printf("Opção inválida!\n");
        printf("Digite uma opção válida:\n");
        printf("1 - Compressão\n2 - Descompressão");
    }
    return 0;
}

#endif //STRING_HEADER_H