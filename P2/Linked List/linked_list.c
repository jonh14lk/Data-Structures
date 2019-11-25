#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node node;

struct node // struct com os nos
{
    int item ;
    node *next;
};
node* create_linked_list() // inicializar
{
    return NULL;
}
node* add(node *head , int item) // funcao para adicionar elementos
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node -> item = item;
    new_node -> next = head;
    return new_node;
}
void print_linked_list(node *head) // printar lista
{
    while (head != NULL) 
    {
        printf("%d\n", head -> item) ;
        head = head -> next ;
    }
}
node* search(node *head , int value) // para procurar alguem
{
    while (head != NULL)
    {
        if (head -> item == value)
        {
            return head;
        }

        head = head -> next;
    }

    return NULL;
}
node* remove_node(node *head, int item) // remover no 
{
    node *previous = NULL;
    node *current = head;

    while (current != NULL && current -> item != item) 
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL) 
    {
        return head;
    }

    if (previous == NULL) 
    {
        head = current -> next;
    } 
    else 
    {
        previous -> next = current -> next;
    }

    free(current);
    return head;
}
int main()
{
    node* list = create_linked_list(); 

    int q , i , aux;
    printf("Digite a quantidade de inteiros que voce ira digtar e em seguida digite eles:\n");
    scanf("%d", &q);

    for (i = 0 ; i < q ; i++)
    {
        scanf("%d", &aux);
        list = add(list, aux);
    }

    printf("lista completa:\n");
    print_linked_list(list); 

    int n ;
    printf("Digite um numero para procurar na lista:\n"); 
    scanf("%d", &n);
    if (search(list , n))
    {
        printf("numero encontrado!\n") ;
    }
    else
    {
        printf("numero nao encontrado ;-; \n") ;
    }
    
    printf("Digite um numero para remover da lista:\n");
    scanf("%d", &n);
    list = remove_node(list , n);   
    printf("Lista com o elemento removido:\n");
    print_linked_list(list);
}
