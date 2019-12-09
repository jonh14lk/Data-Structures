// The Huxley - 2089 (Happy Number) using pointers to functions

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

bool verify (int sum , int i , int results [])
{ 
    int j ;

    for (j = 0 ; j < i ; j++)
    {
        if (results[i] == sum) return true ;
    }

    return false ;
}
bool happy (int (*f)(int num) , int n , int m , int i , int results [])
{
    int sum = 0 , aux ;
    results[i] = m ;

    while (1)
    {
        aux = m % 10 ;
        m = m / 10 ;

        sum += (*f)(aux) ;

        if (m == 0)
        {
            if (sum == 1) return true ;
            else if (verify(aux , i , results)) return false ;
            
            return happy(f , n , sum , i + 1 , results);
        }
    }
}
int calc (int num)
{ 
    return pow(num , 2);
}
int main() 
{
    int n ;
    int results [1000] ;
    scanf("%d", &n);
    memset(results , 0 , sizeof(results));

    if (happy(calc , n , n , 0 , results)) printf("S\n");
    else printf("N\n");

    return 0;
}