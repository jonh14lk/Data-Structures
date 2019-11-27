#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_STACK_SIZE 1000

typedef struct stack stack ;

struct stack // struct da pilha
{
    int current_size;
    int items[MAX_STACK_SIZE];
};
stack* create_stack() // funcao para criar a stack
{
    stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack -> current_size = 0;
    return new_stack;
}
int is_empty(stack *stack) // diz se a pilha esta vazia ou nao
{
    return (stack -> current_size == 0);
}
void push(stack *stack , int item) // adiciona um elemento no topo da pilha
{
    if (stack -> current_size == MAX_STACK_SIZE) 
    {
        printf("Stack overflow\n");
    } 
    else 
    {
        stack -> items[stack -> current_size++] = item ;
    }
}
int pop(stack *stack) // remove o elemento do topo
{
    if (is_empty(stack)) 
    {
        printf("Stack underflow\n");
        return -1;
    } 
    else 
    {
        return stack -> items[--stack -> current_size] ;
    }
}
int peek(stack *stack) // diz qual o elemento que esta no topo
{
    if (is_empty(stack)) 
    {
        //printf("Stack underflow\n");
        return -1;
    } 
    else 
    {
        return stack -> items[stack -> current_size - 1] ;
    }
}
int main ()
{
    stack* stack = create_stack();

    printf("Digite quantos valores irão ser colocados na pilha e sem seguida digite eles\n");
    int q , aux;
    scanf("%d", &q);
    int q2 = q ;

    while(q--)
    {
        scanf("%d", &aux);
        push(stack , aux);
    }

    printf("desempilhando\n");
    
        while(peek(stack) != -1)
        {
            printf("%d está no topo da pilha!\n" , peek(stack));
            printf("%d removido!\n\n" , pop(stack));
        }
    

    return 0 ;
}
