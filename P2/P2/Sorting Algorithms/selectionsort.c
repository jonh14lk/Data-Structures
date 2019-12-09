#include <stdio.h>

void swap(int *a , int *b)  
{  
    int aux = *a ;   
    *a = *b ;   
    *b = aux ;  
} 
void selection_sort(int s[] , int n)
{
    int i, j, min;

    for (i = 0; i < n; i++) 
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (s[j] < s[min])
            {
                min = j;
            }
        }

        swap(&s[i], &s[min]);
    }
}
int main ()
{
	int n , i ;
	scanf("%d", &n);
	int s[n] ;

	for (i = 0 ; i < n ; i++) scanf("%d", &s[i]); 

	selection_sort(s , n); 

	for (i = 0 ; i < n ; i++) printf("%d\n", s[i]);

	return 0 ;
}