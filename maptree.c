#include <stdio.h>
#include "stringList.h"
#include "priorityQueue.h"
#include "hash_table.h"
#include "frequencyCounter.h"


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

Hashtable* maptreeHashTable(Node* current, Node_String* binary_value, Hashtable *hashtree)
{
    if(current-> p_left == NULL && current-> p_right == NULL){ 		//se (o ponteiro aponta pra uma folha)
        hashtree = put(hashtree, current->n_character, binary_value);
        return hashtree;
        //hashtree = put(hashtree, current-> n_character, binary_value);	//coloca na hash a chave(caracter) e valor(binário)
    }

    else{							//se não é folha, então é representado por '*' na árvore
        Node_String* left =insert_node(binary_value, '0');
        hashtree = maptreeHashTable(current-> p_left, left, hashtree);	//percorre a árvore a esquerda e add '0'
        Node_String* right =insert_node(binary_value, '1');
        hashtree = maptreeHashTable(current-> p_right, right, hashtree);//percorre a árvore a direita e add '1'
    }
    return hashtree;
}


//
// Created by alvino on 03/10/16.
//

