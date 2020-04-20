#include "iostream"

int main()
{
    int n ;
    std::cin >> n ;
    long long inputlist[n] ;
    for (int i = 0 ; i < n ; i++)
    {
        std::cin >> inputlist[i] ;
    }
    
    long long maxs[n+1] ;
    int maxi = 0 ;
    long long currentmax = 0 ;

    for (int i = 0 ; i < n ; i++)
    {
        if (inputlist[i] >= currentmax)
        {
            maxs[maxi] = currentmax ;
            maxi++ ;
            currentmax = inputlist[i] ;
        }
        else
        {
            while (inputlist[i] < maxs[maxi-1])
            {
                maxi-- ;
                if (maxi == 1)
                {
                    break ;
                }
            }
        }
    }
    std::cout << maxi ;
}
