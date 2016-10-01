#include <stdio.h>
Hashtable* hashtree = create_hash_table(); // criando a hash que receberá as chaves e valores das folhas da árvore

void maptree(node* current, string binary_value, string representree){				//função recebe um ponteiro e uma string
	if(current-> p_left == NULL && current-> p_right == NULL){ 		//se (o ponteiro aponta pra uma folha)
		if(current->character == '*'|| current->character == '!'){	//se o caracter for '*' ou '!'
			representree += '!';				//vetor representação da árvore recebe um marcador
		}
		representree += current->character;			//vetor representação da árvore recebe o caracter da folha

		put(hashtree, current-> character, current-> binary_value);	//coloca na hash a chave(caracter) e valor(binário)
	}

	else{							//se não é folha, então é representado por '*' na árvore
		representree +='*';
		maptree(current-> p_left, current-> binary_value += '0');	//percorre a árvore a esquerda e add '0'
		maptree(current-> p_right, current-> binary_value += '1');//percorre a árvore a direita e add '1'
	}
}

struct node{
  unsigned char n_character;
  int n_frequency; 
  Node *Next;
  Node *p_left;
  Node *p_right;

  int n_binary_value;
  unsigned char n_representree; // Será criada na main como string NÃO PODE SER PARAMETRO DO NÓ
  
};
