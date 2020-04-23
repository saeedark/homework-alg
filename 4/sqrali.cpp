#include "iostream"

int main()
{
    int n ;
    std::cin >> n ;
    int inp[n] ;
    int max = 0 ;
    unsigned long long int res = 0 ;
    int diff ;
    for (int i = 0 ; i < n ; i++)
    {
        std::cin >> inp[i] ;
        max = ( inp[i] > max ) ? inp[i] : max ;
    }
    inp[0] = max - inp[0] ;
    res += inp[0] ;
    for (int i = 1 ; i < n ; i++)
    {
        inp[i] = max - inp[i] ;
        diff = inp[i] - inp[i-1] ;
        if ( diff > 0)
        {
            res += diff ; 
        }
    }
    std::cout << res ;
}
