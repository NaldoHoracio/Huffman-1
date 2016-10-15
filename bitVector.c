//
// Created by alvino on 15/10/16.
//
#include "stringList.h"

Node_String* getBits(Node_String *str)
{
    int str_size = size(str);
    int cont=1, i;
    int aux=0;
    Node_String* output = create_linked_list();
    for(i = 0 ; i < str_size ; i++)
    {
        char c = find(str, i);
        if(cont%9!=0)
        {
            aux = aux << 1;
            if(c =='1')
            {
                aux = aux + 1;

            }
            cont++;
        }
        else
        {
            cont=1;
            output = insert_node(output, aux);
            aux=0;
            i--;
        }

    }
    if(cont!=0)
    {
        output = insert_node(output, aux);
    }
    return output;
}

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