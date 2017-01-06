//
// Created by alvino on 01/10/16.
//
#ifndef STRING_LIST_C
#define STRING_LIST_C
#include "stringList.h"

Node_String* create_linked_list() //cria uma lista vazia
{
    return NULL;
}
int is_empty(Node_String *first) // verifica se a lista está vazia
{
    return (first == NULL);
}
Node_String* insert_node(Node_String *first, char item) //insere um nó no final da lista (string dinamica)
{
    Node_String *p = first;
    if(first == NULL) //se a lista estiver vazia
    {
        Node_String *new_node = (Node_String*)malloc(sizeof(Node_String));
        new_node->item = item;
        new_node->next_node = NULL;
        return new_node;
    }
    while(p->next_node != NULL) //percorre a lista até encontrar o último elemento
    {
        p = p->next_node;
    }
    Node_String *new_node = (Node_String*)malloc(sizeof(Node_String));
    new_node->item = item;
    p->next_node = new_node;
    new_node->next_node = NULL;
    return first;
}
void print_linked_list(Node_String *first) //imprime a string
{
    Node_String *p;
    for( p = first; p != NULL; p = p->next_node)
        printf("%c", p->item);
}
Node_String* search_linked_list(Node_String *first, char item) //função de procura por um item
{
    Node_String *p;
    for( p = first; p != NULL; p = p->next_node)
    {
        if(p->item == item)
            return p;
    }
}

char find(Node_String *first, int position) //função de procura através do indice do "vetor" (tal qual um "acesso direto")
{
    Node_String*p;
    int count=0;
    for(p = first; p != NULL; p = p->next_node)
    {
        if(position == count)
            return p->item;

        count++;
    }
    printf("Not found\n");
}

int size(Node_String *first) //retorna o tamanho da lista (string)
{
    Node_String *p;
    int count = 0;
    for(p = first; p != NULL; p = p->next_node)
    {
        count++;
    }
    return count;
}

char* c_str(Node_String *first, char* str) //transforma a string dinamica (lista) em um vetor de char
{
    if(first == NULL)
        return NULL;
    int siz = size(first);
    int i = 0;
    Node_String *p;
    str = (char*)malloc(sizeof(char)*(siz+3)); //alloca um vetor tipo char com tamanho da lista
    //char str[100];
    for(p = first; p != NULL; p = p->next_node) //transfere item a item da lista para cada posição do vetor char
    {
        str[i] = p->item;
        i++;
    }
    str[i]='\0';
    return str;
}

Node_String* buildList(Node_String *first, char *str) //constroi uma lista a partir de um vetor char
{
    if(str == NULL)
        return NULL;
    int size = strlen(str);
    int i;
    for(i = 0; i < size; i++) //insere item a item do vetor na lista(string)
    {
        first = insert_node(first, str[i]);
    }
    return first;
}

Node_String* insert_Node_String(Node_String *first, Node_String *String) //insere uma string no final da lista (string dinamica)
{
    Node_String *p = first;
    Node_String *inserting = String;
    if(first == NULL) //se a lista estiver vazia
    {
        first = inserting;
    }
    else
    {
        while (p->next_node != NULL) //percorre a lista até encontrar o último elemento
        {
            p = p->next_node;
        }
        p->next_node = inserting;
    }
    return first;
}

Node_String* removeLast(Node_String* first)
{
    Node_String* p;
    p = first;
    if(p->next_node == NULL)
    {
        return NULL;
    }
    while (p->next_node->next_node != NULL) //percorre a lista até encontrar o último elemento
    {
        p = p->next_node;
    }
    p->next_node = NULL;
    return first;
}

Node_String* pop (Node_String* first) // Remover o primeiro nó
{
    if(first == NULL)
        return NULL;
    first = first->next_node;
    return first;
}

Node_String* decToBin(int num, Node_String* str, int idx) // decimal to binario
{
    int i = 0, j, aux;
    char bin[15];
    char result = (char) num;
    for(i = idx ; i >=0 ; i--)
    {
        aux = num >> i;
        if(aux & 1)
        {
            bin[idx-i] = '1' ;
        }
        else
        {
            bin[idx-i] = '0' ;
        }
    }
    for(i = 0 ; i <= idx ; i++)
    {
        str = insert_node(str, bin[i]);

    }
    return str;
}

/*
int main()//testa as funções
{
    Node_String* list = create_linked_list();
    Node_String* lista = create_linked_list();
    int y=0;
    char x;
    char *n;
    puts("Digite os elementos da lista: ");
    scanf("%c", &x);
    while( y!=10)
    {
        list = insert_node(list, x);
        lista = insert_node(lista, x+1);
        puts("Digite outro elemento para adicionar na lista:");
        scanf("%c", &x);
        y++;
    }

    puts("LISTA ENCADEADA");
    print_linked_list(list);
    printf("\n");
    print_linked_list(lista);
    printf("\n");
    list = insert_Node_String(list, lista);
    print_linked_list(list);
    printf("\n");
    //puts("Digite o elemento que voce quer buscar: ");
    //scanf("%c", &x);
    /*if(search_linked_list(list,x))
        printf("This element exist it is %c\n",x);
    else
        printf("Element does not exist.\n");

    printf("size is %d\n", size(list));/*
    scanf("%d", &y);
    printf("%c\n", find(list,y));
    n=c_str(list, n);
    printf("%u", (unsigned)strlen(n));
    for(y=0;y<strlen(n);y++)
    {
        printf("%c\n", n[y]);
    }
    Node_String *f = create_linked_list();
    f=buildList(f, n);
    print_linked_list(f);

    free(list);

    return 0;
}
*/

#endif// STRING_LIST_C
