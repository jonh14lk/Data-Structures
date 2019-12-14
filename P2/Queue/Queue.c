#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct queue queue ;
#define MAX_QUEUE_SIZE 100000

// queue
struct queue 
{
    int current_size;
    int head;
    int tail;
    int items[MAX_QUEUE_SIZE];
};
queue* create_queue()
{
    queue *new_queue = (queue*) malloc(sizeof(queue)) ;
    new_queue -> current_size = 0 ;
    new_queue -> head = 0 ;
    new_queue -> tail = MAX_QUEUE_SIZE – 1 ;
    return new_queue ;
}
void enqueue(queue *queue, int item)
{
    if (queue->current_size >= MAX_QUEUE_SIZE) printf("Queue overflow");
    else 
    {
        queue -> tail = (queue -> tail + 1) % MAX_QUEUE_SIZE ;
        queue -> items[queue -> tail] = item ;
        queue -> current_size++ ;
    }
}
int dequeue(queue *queue)
{
    if (is_empty(queue)) 
    {
        printf("Queue underflow");
        return -1;
    } 
    else 
    {
        int dequeued = queue -> items[queue -> head] ;
        queue -> head = (queue -> head + 1) % MAX_QUEUE_SIZE ;
        queue -> current_size-- ;
        return dequeued ;
    }
}

// priority_queue
struct node 
{
    int item ;
    int priority ;
    node *next ;
};
struct priority_queue 
{
    node *head ;
};
void enqueue(priority_queue *pq, int i, int p)
{
    node *new_node = (node*) malloc(sizeof(node)) ;
    new_node -> item = i ;
    new_node -> priority = p ;

    if ((is_empty(pq)) || (p > pq->head->priority)) 
    {
        new_node -> next = pq -> head ;
        pq -> head = new_node ;
    } 
    else 
    {
        node *current = pq -> head ;

        while ((current -> next != NULL) && (current -> next -> priority > p)) current = current -> next ;

        new_node -> next = current -> next ;
        current -> next = new_node ;
    } 
}
node* dequeue(priority_queue *pq)
{
    if (is_empty(pq)) 
    {
        printf("Priority Queue underflow\n");
        return NULL;
    } 
    else 
    {
        node *node = pq -> head ;
        pq -> head = pq -> head -> next ;
        node -> next = NULL ;
        return node ;
    }
}
int maximum(priority_queue *pq)
{
    if (is_empty(pq)) 
    {
        printf("Priority Queue underflow") ;
        return -1 ;
    } 
    else 
    {
        return pq -> head -> i ;
    }
}
int main ()
{
    return 0 ;
}