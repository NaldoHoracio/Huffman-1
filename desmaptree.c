//
// Created by alvino on 17/10/16.
//

#include "desmaptree.h"
#include "stringList.h"
#include "priorityQueue.h"

int main()
{
    Node_String* list = create_linked_list();
    int y=0, P;
    char x;
    char *n;
    P=9;
    puts("Digite os elementos da lista: ");
    scanf("%c", &x);
    while( y!=P)
    {
        list = insert_node(list, x);
        puts("Digite outro elemento para adicionar na lista:");
        scanf("%c", &x);
        y++;
    }
    //print_linked_list(list);
    //list = getLeft(list);
    pop(list);
    print_linked_list(list);
    printf("\n");
}
