#include "stringList.h"

struct node
{
    char item;
    struct node *next_node;
};
Node* create_linked_list()
{
    return NULL;
}
int is_empty(Node *first)
{
    return (first==NULL);
}
Node* insert_node(Node *first, char item)
{
	Node *p=first;
	if(first==NULL)
	{
		Node *new_node = (Node*)malloc(sizeof(Node));
    	new_node->item = item;
		new_node->next_node = NULL;
		return new_node;
	}
	while(p->next_node != NULL)
	{
		p=p->next_node;
	}
	Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->item = item;
	p->next_node = new_node;
    new_node->next_node = NULL;
    return first;
}
void print_linked_list(Node *first)
{
    Node *p;
    for( p=first; p!=NULL; p=p->next_node)
        printf("%c", p->item);
}
Node* search_linked_list(Node *first, char item)
{
    Node *p;
    for( p=first; p!=NULL; p=p->next_node)
    {
        if(p->item==item)
            return p;
    }
}

char find(Node *first, int position){
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

int size(Node *first)
{
	Node *p;
	int count=0;
	for(p=first; p!=NULL; p=p->next_node)
	{
		count++;
	}
	return count;
}

char* c_str(Node *first, char* str)
{
	int siz=size(first);
	int i=0;
	Node *p;
	str = (char*)malloc(sizeof(char)*(siz+3));
	//char str[100];
	for(p=first; p!=NULL; p=p->next_node)
	{
		str[i]=p->item;
		i++;
	}
	str[i]='\0';
	return str;
}

Node* buildList(Node *first, char *str)
{
	int size= strlen(str);
	int i;
	for(i=0; i<size; i++)
	{
		first=insert_node(first, str[i]);
	}
	return first;
}

int main()
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
