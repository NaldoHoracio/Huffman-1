//
// Created by alvino on 03/10/16.
//
#ifndef MAPTREE_C
#define MAPTREE_C

#include "maptree.h"
/*main()
{
    Hashtable* hashtree = create_hash_table(); // criando a hash que receberá as chaves e valores das folhas da árvore
    Node_String* representree = create_linked_list(); // criando a lista encadeada representação da árvore
    Node_String* binary_value = create_linked_list(); //criando a lista encadeada binary_value
}
*/
//função recebe um ponteiro e uma string
Node_String* maptreeRepresetantion(Node* current, Node_String* representree, Node_String* binary_value, Hashtable* hashtree)
{
	if(current-> p_left == NULL && current-> p_right == NULL){ 		//se (o ponteiro aponta pra uma folha)
		if(current->n_character == '*'|| current->n_character == '!'){	//se o caracter for '*' ou '!'
			representree = insert_node(representree, '!');				//lista representação da árvore recebe um marcador
		}
		representree = insert_node(representree, current->n_character);	//vetor representação da árvore recebe o caracter da folha
		return representree;
		//hashtree = put(hashtree, current-> n_character, binary_value);	//coloca na hash a chave(caracter) e valor(binário)
	}

	else{							//se não é folha, então é representado por '*' na árvore
		representree = insert_node(representree, '*');
		Node_String* left =insert_node(binary_value, '0');
		Node_String* right =insert_node(binary_value, '1');
		representree = maptreeRepresetantion(current-> p_left, representree, left, hashtree);	//percorre a árvore a esquerda e add '0'
		representree = maptreeRepresetantion(current-> p_right, representree, right, hashtree);//percorre a árvore a direita e add '1'
	}
	return representree;
}

Hashtable* maptreeHashTable(Node* current, long int binary_value, Hashtable *hashtree)
{
	if(current-> p_left == NULL && current-> p_right == NULL){ 		//se (o ponteiro aponta pra uma folha)
		hashtree = putI(hashtree, current->n_character, binary_value);
		printf("valor = %ld(%c)\n", getI(hashtree, current->n_character), current->n_character);
		//getI(hashtree, current->n_character);

		return hashtree;
		//hashtree = put(hashtree, current-> n_character, binary_value);	//coloca na hash a chave(caracter) e valor(binário)
	}

	else{							//se não é folha, então é representado por '*' na árvore

		//Node_String* left = buildList(left, binary_value);
		//left = insert_node(left, '0');
		//char* left_c = c_str(left, left_c);
		long int left = binary_value * 10;//
		hashtree = maptreeHashTable(current-> p_left, left, hashtree);	//percorre a árvore a esquerda e add '0'

		//Node_String* right =buildList(right, binary_value);
		//right = insert_node(right, '1');
		//char* right_c = c_str(right, right_c);
		long int right = binary_value * 10 + 1;
		hashtree = maptreeHashTable(current-> p_right, right, hashtree);//percorre a árvore a direita e add '1'
	}
	return hashtree;
}

int getTrash(FILE* file)
{

	fseek(file, 0, SEEK_SET);
	unsigned char trashSize = getc(file);
	trashSize = trashSize >> 5 ;
	return trashSize;
}

int getSizeTree(FILE* file)
{
	fseek(file, 0, SEEK_SET);

	unsigned char first  = getc(file);
	unsigned char second = getc(file);
	first = first & 00011111;
	int size = (first << 8) | second;

	return size;
}

Node_String* getTree_Representation(FILE* file, Node_String* tree, int sizeTree, int sizeName)
{
	char c;
	int i;
	for( i = 3 + sizeName; i < sizeName + sizeTree + 3 ;  i++)
	{
		fseek(file, i, SEEK_SET);
		c = getc(file);
		tree = insert_node(tree,c);
	}
	return tree;
}

int sizeBytes(FILE* file)
{
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	return size;
}

int getSizeName(FILE* file)
{
	fseek(file, 2, SEEK_SET);
	unsigned char size = getc(file);
	return size;
}

Node_String* getName(FILE* file, Node_String* tree, int sizeName)
{
	char c;
	int i;
	for( i = 3; i < sizeName + 3 ;  i++)
	{
		fseek(file, i, SEEK_SET);
		c = getc(file);
		tree = insert_node(tree,c);
	}
	return tree;
}

#endif// MAPTREE_C
