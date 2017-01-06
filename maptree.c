//
// Created by edvonaldoh on 15/10/16.
//
#ifndef MAIN_C
#define MAIN_C
#include "header.h"

int main()
{
    FILE *file;
    FILE *output;
    char num_c[10000];// Chavar variável para colocar no arquivo
    char name_file[100];// Nome do arquivo
    long size_file;// tamanho do arquivo
    int aux_size, size_trash, size_tree;// Auxilar para calcular, tamanho do lixo, e var. para tamanho do lixo
    Node_String *str = create_linked_list();
    Node_String *str_codification = create_linked_list();
    int i, op;// Operador para escolher a opcao desejada
    int aux, position;// Auxiliar para verficar arquivo e auxiliar para posição da string de codificação
    printf("Digite o que você deseja fazer:\n");
    printf("1 - Compressão\n");
    printf("2 - Descompressão\n");
    printf("Outro numero - Sair\n");
    scanf("%d", &op);
    while (op == 1 || op == 2)
    {
        if(op == 1)// Opção compressão
        {
            printf("Digite o nome do arquivo que deseja comprimir:\n");
            scanf("%s", name_file);// Nome do arquivo
            file = fopen (name_file,"rb");
            // Testando se o arquivo existe ou não
            if (file == NULL) {
                printf("O arquivo não existe neste diretório.\n");
            } else {
                while((aux = fgetc(file))) { //percorre os caracteres do arquivo
                    if (aux == EOF) break; //encerrar caso o arquivo esteja no fim
                    arrayFrequency[aux] += 1; //caso contrário adiciona 1 para a contagem daquele caracetere
                }
                fclose(file); //fecha o arquivo
                Node *pq = createPriorityQueue();// Criando uma fila
                for (i = 0; i < 256; i++)  //percorrendo o array
                {

                    if (arrayFrequency[i] > 0) {
                        pq = insert(pq, (char) i, arrayFrequency[i]);  // Inserindo os nós caracteres com sua respectiva frequência
                        //printf("Frequency %d --> %c position\n", arrayFrequency[i], i);    // imprimindo tabela de frequencia

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
                print_hash_table(hashtree);
                printf("\n\n");
                long int num;
                while ( aux = fgetc(file) )// Lendo cada caractere
                {
                    if (aux == EOF) break;  //encerrar caso o arquivo esteja no fim
                    num = getI(hashtree, aux);// Get na codificação do caractere na chave

                    sprintf(num_c, "%ld", num);// Transforma num em string
                    str = buildList(NULL, num_c);// String em Node_String
                    str = pop(str);// Dá pop para tirar o primeiro elemento
                    //printf("%c --> ", aux);
                    //print_linked_list(str);

                    // Concatena uma string com a outra a fim de gerar a codificação
                    str_codification = insert_Node_String(str_codification, str);

                }
                fclose(file);
                printf("Digite o nome do arquivo de saida : (XXX.huff):");
                scanf("%s", num_c);
                Node_String* StringName = buildList(StringName, name_file);
                output = fopen (num_c ,"wb");
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
                fprintf(output, "%c", (unsigned char)size(StringName));
                fprintf(output, "%s",c_str(StringName, num_c));
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
            int sizeTrash;
            int sizeTotal;
            int sizeTree;
            int sizeName;
            Node_String* tree = create_linked_list();
            Node_String* Name;
            printf("Descompressão\n");
            FILE* codification ;
            FILE* output;
            printf("Digite o nome do arquivo que deseja descomprimir:\n");
            scanf("%s", name_file);
            codification =  fopen(name_file, "rb");
            sizeTotal = sizeBytes(codification);
            sizeTrash = getTrash(codification);
            sizeTree = getSizeTree(codification);
            sizeName = getSizeName(codification);
            tree = getTree_Representation(codification, tree, sizeTree, sizeName);
            Name = getName(codification, Name, sizeName);
            printf("Tamanho total do arquivo:%d\n",sizeTotal);
            printf("Tamanho total do nome do arquivo:%d\n",sizeName);
            printf("Nome do arquivo:%s\n",c_str(Name, num_c));
            printf("Tamanho do lixo = %d\n", sizeTrash);
            printf("Tamanho da arvore = %d\n", sizeTree);
            printf("Representacao da arvore:");
            print_linked_list(tree);
            printf("\n");
            Node* root = rebuild_tree(tree);
            //print_linked_list(tree);
            //printf("root=%c\n", root->n_character);
            Node* root_aux = root;
            output = fopen (c_str(Name, num_c), "wb+");
            fseek(codification, sizeTree +sizeName+ 3, SEEK_SET);     //Posiciona o ponteiro na posição inicial da codificação
            unsigned int bit_current = 0;
            int j;
            for(i = 0; i < (sizeTotal - sizeTree - sizeName  - 3 - 1); i++)  //Percorre (até antes do byte de lixo) a arvore e decodifica o arquivo
            {
                bit_current = getc(codification);
                //printf("i=%d", i);
                for(j = 7; j >= 0; j--)
                {
                    // Verifica se o bit de posição i do caractere c está setado - tem valor 1
                    if(get_bit(bit_current, j))
                    {
                        root_aux = root_aux->p_right;
                    }
                    else
                    {
                        root_aux = root_aux->p_left;
                    }
                    if(root_aux->p_left==NULL && root_aux->p_right==NULL)
                    {
                        fprintf(output, "%c", root_aux->n_character);
                        printf("%c", root_aux->n_character);
                        root_aux = root;
                    }
                }
            }

            bit_current = getc(codification);
            for(j = 7; j >= sizeTrash; j--)
            {

                if(get_bit(bit_current, j))
                {
                    root_aux = root_aux->p_right;
                }
                else
                {
                    root_aux = root_aux->p_left;
                }
                if(root_aux->p_left==NULL && root_aux->p_right==NULL)
                {
                    fprintf(output, "%c", root_aux->n_character);
                    //printf("%c", root_aux->n_character);
                    root_aux = root;
                }
            }

            fclose(codification);
        }
        printf("Digite novamente o que fazer: (1 - Compressão/2 - Descompressão/Outro numero - Sair)\n");
        scanf("%d", &op);
    }
    return 0;
}

#endif// MAIN_C
