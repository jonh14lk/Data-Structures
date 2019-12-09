#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *v;
    int n ;

    scanf("%d", &n);

    v = malloc(n * sizeof(int)); 

    if (v == NULL) 
    {
        printf("Could not allocate memory!\n");
    } 
    else 
    {
        printf("we can allocate memory!\n");
    }

    free (v); // we can deallocate memory

	return 0 ;
}