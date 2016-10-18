//
// Created by edvonaldoh on 15/10/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "header.h"
#include "frequencyCounter.h"
#include "frequencyCounter.c"
#include "hash_table.h"
#include "hash_table.c"
#include "helpful.h"
#include "helpful.c"
#include "maptree.h"
#include "maptree.c"
#include "priorityQueue.h"
#include "priorityQueue.c"
#include "stringList.h"
#include "stringList.c"
#include "bitVector.h"
#include "bitVector.c"
#include "size_hash_size_trash.h"
void compress(char * intput, char * output)
{

}
void decompress(char * intput)
{

}

int main()
{
    FILE *file;
    FILE *output;
    char num_c[10000];
    char name_file[100];
    long size_file;
    int key;
    int aux_size, size_trash, size_tree;// Auxilar para calular tamanho do lixo e var. para tamanho do lixo
    Node_String *str = create_linked_list();
    Node_String *str_codification = create_linked_list();

    int i, op;// Operador para escolher a opcao desejada
    int aux, position;// Auxiliar para verficar arquivo e auxiliar para posição da string de codificação
    printf("Digite o que você deseja fazer:\n");
    printf("1 - Compressão\n2 - Descompressão\n");
    scanf("%d", &op);

    if(op == 1)// Opção compressão
    {
        printf("Digite o nome do arquivo para fazer compressão:\n");
        scanf("%s", name_file);// Nome do arquivo
        file = fopen (name_file,"rb");
        // Testando se o arquivo existe ou não
        if (file == NULL) {
            printf("O arquivo não existe neste diretório.\n");
        } else {
                while((aux=fgetc(file))) { //percorre os caracteres do arquivo
                    if (aux == EOF) break; //encerrar caso o arquivo esteja no fim
                    arrayFrequency[aux] += 1; //caso contrário adiciona 1 para a contagem daquele caracetere
                }
            fclose(file); //fecha o arquivo
            Node *pq = createPriorityQueue();// Criando uma fila
            for (i = 0; i < 256; i++)  //percorrendo o array
            {

                if (arrayFrequency[i] > 0) {
                    pq = insert(pq, (char) i,
                                arrayFrequency[i]);  // Inserindo os nós caracteres com sua respectiva frequência
                    //printf("Frequency %d --> %d position\n", arrayFrequency[i], i);    // imprimindo tabela de frequencia

                }
            }
                    //counter(name_file); // Lê e conta a frequencia

                //printPriorityQueue(pq);
                Hashtable *hashtree = create_hash_table(); // criando a hash que receberá as chaves e valores das folhas da árvore
                Node_String *representree = create_linked_list(); // criando a lista encadeada representação da árvore
                Node_String *binary_value = create_linked_list(); //criando a lista encadeada binary_value
                pq = buildTree(pq);// Montando a arvore de Huffman
                representree =  maptreeRepresetantion(pq, representree, binary_value, hashtree);// Mapeando a árvore, criando a codificação e guardando na hash
                size_tree = size(representree);
                //print_linked_list(representree);
                printf("\n");
                hashtree = maptreeHashTable(pq, 1, hashtree);
                file = fopen(name_file, "rb");
                //printf("Hash_tree:\n");
                //print_hash_table(hashtree);
                printf("\n\n");
                long int num;
                while ( aux = fgetc(file) )// Lendo cada caractere
                {
                    if (aux == EOF) break;  //encerrar caso o arquivo esteja no fim
                    num = getI(hashtree, aux);// Get na codificação do caractere na chave

                    sprintf(num_c, "%ld", num);
                    str = buildList(NULL, num_c);
                    str = pop(str);
                    //printf("%c --> ", aux);
                    //print_linked_list(str);

                    str_codification = insert_Node_String(str_codification, str);// Concatena uma string com a outra a fim de gerar a codificação

                }
            fclose(file);
            output = fopen ("saida.huff","wb");
            //printf("\n%d\n", size(str_codification));
            //print_linked_list(str_codification);
            //TAMANHO DO LIXO E TAMANHO DA ÁRVORE
            aux_size = size(str_codification);
            aux_size = aux_size % 8;
            size_trash = 8 - aux_size;
            //printf("Size trash %d\n\n", size_trash);
            str = NULL;
            str = decToBin(size_trash, str, 2);
            str = insert_Node_String(str, decToBin(size_tree,NULL, 12));
            //print_linked_list(str);
            str = getBits(str);
            //printf("r=%d", (unsigned char)find(str, 0));
            fprintf(output, "%c",(unsigned char) find(str, 0));
            fprintf(output, "%c", (unsigned char) find(str, 1));
            fprintf(output, "%s", c_str(representree, num_c));
            str_codification = getBits(str_codification);
            //print_linked_list(str_codification);
            fprintf(output, "%s", c_str(str_codification, num_c));
            char c = find(str_codification, size(str_codification)-1);
            fprintf(output, "%c", c);
            fclose(output);
            //print_linked_list(str);
        }


    }
    else if(op == 2)// Opção descompressão
    {
        printf("Descompressão\n");
    }
    else
    {
        printf("Opção inválida!\n");
        printf("Digite uma opção válida:\n");
        printf("1 - Compressão\n2 - Descompressão\n");
        printf("\n\n");
    }
    return 0;
}

