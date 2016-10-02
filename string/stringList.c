#include "stringList.h"

struct node  // define um nó
{
    char item; // contendo um caracter
    struct node *next_node; //um ponteiro pro proximo nó
};
Node* create_linked_list() //cria uma lista vazia
{
    return NULL;
}
int is_empty(Node *first) // verifica se a lista está vazia
{
    return (first==NULL);
}
Node* insert_node(Node *first, char item) //insere um nó no final da lista (string dinamica)
{
    Node *p=first;
    if(first==NULL) //se a lista estiver vazia
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->item = item;
        new_node->next_node = NULL;
        return new_node;
    }
    while(p->next_node != NULL) //percorre a lista até encontrar o último elemento
    {
        p=p->next_node;
    }
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->item = item;
    p->next_node = new_node;
    new_node->next_node = NULL;
    return first;
}
void print_linked_list(Node *first) //imprime a string
{
    Node *p;
    for( p=first; p!=NULL; p=p->next_node)
        printf("%c", p->item);
}
Node* search_linked_list(Node *first, char item) //função de procura por um item
{
    Node *p;
    for( p=first; p!=NULL; p=p->next_node)
    {
        if(p->item==item)
            return p;
    }
}

char find(Node *first, int position) //função de procura através do indice do "vetor" (tal qual um "acesso direto")
{
    Node*p;
    int count=0;
    for(p=first; p!=NULL; p=p->next_node)
    {
        if(position==count)
            return p-> item;

        count++;
    }
    printf("Not found\n");
}

int size(Node *first) //retorna o tamanho da lista (string)
{
    Node *p;
    int count=0;
    for(p=first; p!=NULL; p=p->next_node)
    {
        count++;
    }
    return count;
}

char* c_str(Node *first, char* str) //transforma a string dinamica (lista) em um vetor de char
{
    int siz=size(first);
    int i=0;
    Node *p;
    str = (char*)malloc(sizeof(char)*(siz+3)); //alloca um vetor tipo char com tamanho da lista
    //char str[100];
    for(p=first; p!=NULL; p=p->next_node) //transfere item a item da lista para cada posição do vetor char
    {
        str[i]=p->item;
        i++;
    }
    str[i]='\0';
    return str;
}

Node* buildList(Node *first, char *str) //constroi uma lista a partir de um vetor char
{
    int size= strlen(str);
    int i;
    for(i=0; i<size; i++) //insere item a item do vetor na lista(string)
    {
        first=insert_node(first, str[i]);
    }
    return first;
}

int main()//testa as funções
{
    Node* list = create_linked_list();
    int y=0;
    char x;
    char *n;
    puts("Digite os elementos da lista: ");
    scanf("%c", &x);
    while( y!=10)
    {
        list = insert_node(list, x);
        puts("Digite outro elemento para adicionar na lista:");
        scanf("%c", &x);
        y++;
    }
    puts("LISTA ENCADEADA");
    print_linked_list(list);
    puts("Digite o elemento que voce quer buscar: ");
    scanf("%c", &x);
    if(search_linked_list(list,x))
        printf("This element exist it is %c\n",x);
    else
        printf("Element does not exist.\n");

    printf("size is %d\n", size(list));
    scanf("%d", &y);
    printf("%c\n", find(list,y));
    n=c_str(list, n);
    printf("%u", (unsigned)strlen(n));
    for(y=0;y<strlen(n);y++)
    {
        printf("%c\n", n[y]);
    }

    Node *f = create_linked_list();
    f=buildList(f, n);
    print_linked_list(f);

    free(list);

    return 0;
}
//
// Created by alvino on 01/10/16.
//

