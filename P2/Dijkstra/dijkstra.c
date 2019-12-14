// 1997 - Huxley : Frete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct heap heap;
typedef struct pair pair;
typedef struct adj_list adj_list;
typedef struct graph graph;

#define MAX_SIZE 100000 

struct pair 
{
    int first , second ;
};
struct heap 
{
    pair data[MAX_SIZE] ;
    int size ;
};
struct adj_list
{
    pair data;
    adj_list *next;
};
struct graph 
{
    adj_list *vertex[MAX_SIZE] ;
    int visited [MAX_SIZE] ;
    int size ;
};
void swap(pair *x , pair *y) 
{
    pair a = *x ;
    *x = *y ;
    *y = a ;
}
int get_parent_index(heap *heap, int i)
{
    return i / 2 ;
}
int get_left_index(heap *heap, int i)
{
    return 2 * i ;
}
int get_right_index(heap *heap, int i)
{
    return 2 * i + 1 ;
}
pair item_of(heap *heap, int i)
{
    return heap -> data[i] ;
}
int is_empty (heap *heap) 
{
    return heap -> size == 0 ;
}
graph* create_graph()
{
    graph *g = (graph*) malloc(sizeof(graph));

    int i;

    for (i = 1 ; i <= MAX_SIZE - 1 ; i++) 
    {
        g -> vertex[i] = NULL ;
        g -> visited[i] = 0 ;
    }

    return g ;
}
adj_list* create_adj_list(int v , int dist) 
{
    adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
    pair p;

    p.first = dist ;
    p.second = v ;

    new_adj_list -> data = p ;
    new_adj_list -> next = NULL;

    return new_adj_list;
}
heap *criar_heap(int v) 
{
    heap *h = (heap*) malloc(sizeof(heap)) ;
    h -> size = 0 ; 
    pair p ;
    int i ;

    for (i = 0 ; i < v ; i++) 
    {
        p.first = -1 ;
        p.second = -1 ;
        h -> data[i] = p ;
    }

    return h ;
}
void enqueue(heap *heap, pair item)
{ 
    heap -> data[++heap -> size] = item ;

    int key_index = heap -> size ;
    int parent_index = get_parent_index(heap, heap -> size) ;

    while (parent_index >= 1 && heap -> data[key_index].first > heap -> data[parent_index].first) 
    {
        swap(&heap -> data[key_index], &heap -> data[parent_index]) ;
        key_index = parent_index ;
        parent_index = get_parent_index(heap, key_index) ;
    }
}
void min_heapify(heap *heap, int i) 
{
    int smallest ;
    int left_index = get_left_index(heap, i) ;
    int right_index = get_right_index(heap, i) ;

    if (left_index <= heap -> size && heap -> data[left_index].first < heap -> data[i].first) smallest = left_index ;
    else smallest = i ;

    if (right_index <= heap -> size && heap -> data[right_index].first < heap -> data[smallest].first) smallest = right_index ;

    if (heap -> data[i].first != heap -> data[smallest].first) 
    {
        swap(&heap -> data[i] , &heap -> data[smallest]) ;
        min_heapify(heap, smallest) ;
    }
}
pair dequeue(heap *heap) 
{
    pair p = heap -> data[1] ;

    heap -> data[1] = heap -> data[heap -> size] ;
    --heap -> size ;

    min_heapify(heap , 1) ;
    return p ;
}
void start(graph *graph) 
{
    int i;

    for (i = 0 ; i < graph -> size ; i++) graph -> visited[i] = 0 ;
}
adj_list *insert_end(adj_list *head , int vertex, int distance) 
{
    if (head == NULL) return create_adj_list(vertex, distance) ; 
    else 
    {
        adj_list *current = head ;

        while (current -> next != NULL) current = current -> next ;
        
        current -> next = create_adj_list (vertex, distance) ;
        return head ;
    }
}
void add_edge(graph *graph, int from , int to, int distance) 
{
    graph -> vertex [from] = insert_end(graph -> vertex[from] , to , distance) ;
}
int dijkstra(graph *graph , int source , int distance [] , int n) 
{
    int i ;

    for (i = 1 ; i <= graph -> size ; i++)
    {
        distance[i] = INT_MAX ;
    }
    
    distance[source] = 0 ;

    pair p; 

    p.first = 0 ;
    p.second = source ;

    heap *heap = criar_heap(graph -> size) ;

    enqueue(heap, p) ;

    while (!is_empty(heap)) 
    {
        pair u = dequeue(heap) ;
        adj_list *current = graph -> vertex[u.second] ;

        while (current != NULL)
        {
            int actual_dist = distance [u.second] + current -> data.first ;

            if (actual_dist < distance [current -> data.second]) 
            {
                distance [current -> data.second] = actual_dist;

                p.first = distance [current -> data.second] ;
                p.second = current -> data.second ;

                enqueue(heap , p) ;
            }

            current = current -> next ;
        }
    }

    printf("%d\n", distance[n]);
}
int main ()
{
    graph *g = create_graph();

    int n , m , i , a , b , c;
    scanf("%d%d", &n , &m);
    g -> size = n ;

    int d [MAX_SIZE] ;
    memset(d , INT_MAX , sizeof(d));

    for (i = 0 ; i < m ; i++)
    {
        scanf("%d%d%d", &a , &b , &c);
        add_edge(g , a , b , c);
        add_edge(g , b , a , c);
    }

    dijkstra(g , 1 , d , n) ;

    return 0 ;
}