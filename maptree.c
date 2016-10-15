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
void maptree(Node* current, Node_String* representree, Node_String* binary_value, Hashtable hashtree)	//função recebe um ponteiro e uma string
{
    if(current-> p_left == NULL && current-> p_right == NULL){ 		//se (o ponteiro aponta pra uma folha)
        if(current->n_character == '*'|| current->n_character == '!'){	//se o caracter for '*' ou '!'
            representree = insert_node(representree, '!');				//lista representação da árvore recebe um marcador
        }
        representree = insert_node(representree, current->n_character);	//vetor representação da árvore recebe o caracter da folha

        put(hashtree, current-> n_character, binary_value);	//coloca na hash a chave(caracter) e valor(binário)
    }

    else{							//se não é folha, então é representado por '*' na árvore
        representree = insert_node(representree, '*');
        Node_String* left =insert_node(binary_value, '0');
        Node_String* right =insert_node(binary_value, '1');
        maptree(current-> p_left, representree, left);	//percorre a árvore a esquerda e add '0'
        maptree(current-> p_right, representree, right);//percorre a árvore a direita e add '1'
    }
}


//
// Created by alvino on 03/10/16.
//

