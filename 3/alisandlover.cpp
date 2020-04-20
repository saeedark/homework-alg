#include "iostream"

int main()
{
    int n ;
    
    std::cin >> n ;
    
    long long inpl[n] ;
    long long maxl[n+1] ;
    int maxi = 0 ;
    long long lastmax = 0 ;

    std::cin >> inpl[0] ;
    maxl[0] = inpl[0] ;


    for (int i = 1 ; i < n ; i++)
    {
        std::cin >> inpl[i] ;
        if (inpl[i] > lastmax)
        {
            if (inpl[i] >= maxl[maxi])
            {
                lastmax = maxl[maxi] ;
                maxi++ ;
                maxl[maxi] = inpl[i] ;
            }
        }
        else
        {
            while ( (maxl[maxi] < inpl[i]) && maxi != 0)
            {
                maxi-- ;
            }
            if ( maxi != 0 )
            {
                lastmax = maxl[maxi-1] ;
            }
            else
            {
                lastmax = 0 ;
            }
            maxl[maxi] = inpl[i] ;
        }
    }

    std::cout << maxi+1 ;
}
