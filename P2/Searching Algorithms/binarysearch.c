#include <stdio.h>

int binary_search(int v [] , int size, int element)
{
    int begin = 0;
    int end = size  - 1 ;
    int middle;

    while (begin <= end) 
    {
        middle = (begin + end) / 2;

        if (v[middle] < element) 
        {
            begin = middle + 1;
        } 
        else if (v[middle] > element) 
        {
            end = middle - 1;
        } 
        else 
        {
            return middle;
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

	int result  = binary_search(v , n , v[2]); 

    printf("%d\n", result);

	return 0 ;
}