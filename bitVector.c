//
// Created by alvino on 15/10/16.
//
#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H

#include "bitVector.h"

Node_String* getBits(Node_String *str)
{
    int str_size = size(str);
    int cont = 1, i;
    char aux = 0;
    Node_String* output = create_linked_list();
    for(i = 0 ; i < str_size ; i++)
    {
        char c = find(str, i);
        if(cont % 9 != 0)
        {
            aux = aux << 1;
            if(c == '1')
            {
                aux = aux + 1;

            }
            cont++;
        }
        else
        {
            //printf("\n%d",(unsigned char) aux);
            cont = 1;
            output = insert_node(output, aux);
            aux = 0;
            i--;
        }

    }
    output = insert_node(output, aux);
    //printf("cont = %d\n", cont);
    if(cont != 0)
    {
        output = insert_node(output, (char)aux << (8-cont+1));
    }
    char p = (char)aux<<(8-cont+1);
    output = insert_node(output, '0');
    output = insert_node(output, p+1);
    //print_linked_list(output);
    return output;
}

// Verifica se o bit de posição i do caractere c está setado - tem valor 1
int get_bit(unsigned char c, int i) // Retorna o bit deposição i no byte c
{
	unsigned char mask = 1 << i; 
	return mask & c;//  AND logico
}

unsigned char set_bit(unsigned char c, int i) // Seta para 1 o bit deposição i no byte c
{
	unsigned char mask = 1 << i;
	return mask | c;//  OR logico
}
/*
int main()
{
    int i;
    char c;
    Node_String* str;
    str = create_linked_list();
    for(i = 0 ; i < 10 ; i ++)
    {
        scanf("%c", &c);
        fflush(stdin);
        str = insert_node(str, c);
    }
    Node_String* bitvector = create_linked_list();
    bitvector = getBits(str);
    for(i = 0 ; i < size(bitvector) ; i++)
    {
        printf("%d\n", (int)find(bitvector, i));
        printf("%d\n", size(bitvector));
    }

}
 */
#endif// BIT_VECTOR_H
