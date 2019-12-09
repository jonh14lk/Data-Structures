#include <stdio.h>

int linear_search(int v[], int size, int element)
{
    int i;

    for (i = 0; i < size; i++) 
    {
        if (v[i] == element) 
        {
            return i;
        }
    }

    return -1;
}
int main ()
{
	int n , i ;
	scanf("%d", &n);
	int v[n] ;

	for (i = 0 ; i < n ; i++) scanf("%d", &v[i]); 

	int result = linear_search(v , n , v[2]); 

	printf("%d\n", result);

	return 0 ;
}