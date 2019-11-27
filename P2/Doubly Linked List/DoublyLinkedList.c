#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node node;

struct node // criando a struct do no
{
    int item;
    node *next;
    node *previous;
};
node* create_linked_list() // inicializar
{
    return NULL;
}
int is_empty(node *head) // para ver que nao esta vazio
{
	return (head == NULL);
}
node* add(node *head , int item) // adicionando elementos no inicio
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node -> item = item;
    new_node -> next = head;
    new_node -> previous = NULL;

    if (head != NULL)
    {
        head -> previous = new_node;
    }
    
    return new_node;
}
node* add2(node *head , int item) // adicionando elementos no final
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node -> item = item ;
	new_node -> next = NULL ;
	new_node -> previous = NULL ;
	node *aux = head ; 

	if (!is_empty(head)) 
    {
		while (aux -> next != NULL) 
        {
			aux = aux -> next ;
		}

		aux -> next = new_node ;
		new_node -> previous = aux ;

		return head ;
	} 
    else
    {
	    return new_node ;
	}
}
void print_doubly_linked_list_backward(node *tail) // printar lista voltando
{
    if (tail != NULL)
    {
        printf("%d\n", tail->item);
        print_doubly_linked_list_backward(tail -> previous);
    }
}
void print_linked_list(node *head) // printar lista indo
{
    while (head != NULL) 
    {
        printf("%d\n", head -> item) ;
        head = head -> next ;
    }
}
node* remove_node(node *head, int item) // remover no
{
    node *current = head;

    while (current != NULL && current -> item != item)
    {
         current = current -> next;
    }
   
    if (current == NULL) 
    {
        return head;
    }   

    if (head == current) 
    {
        head = current->next;
    } 

    else 
    {
        current->previous->next = current->next;
    }

    if (current->next != NULL) 
    {
        current->next->previous = current->previous;
    }

    free(current);

    return head;
}
int main()
{
    node* list = create_linked_list(); 

    int q , i , aux , n;
    printf("Digite a quantidade de inteiros que voce ira digtar e em seguida digite eles:\n");
    scanf("%d", &q);

    for (i = 0 ; i < q ; i++)
    {
        scanf("%d", &aux);
        list = add2(list, aux);
    }

    printf("lista completa:\n");
    print_linked_list(list);

    printf("Digite um numero para remover da lista:\n");
    scanf("%d", &n);
    list = remove_node(list , n);   
    printf("Lista com o elemento removido:\n");
    print_linked_list(list);
}