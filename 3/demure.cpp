#include "iostream"

int main()
{
    long n ;
    std::cin >> n ;
    long inarr[n] ;
    
    for (long i = 0 ; i < n ; i++)
    {
        std::cin >> inarr[i] ;
    }
    
    long firstindex = 1 ;
    bool can = false ;
    while (true)
    {
        if(inarr[firstindex] > inarr[firstindex-1])
        {
            firstindex = firstindex-1 ;
            can = true ;
            break;
        }
        firstindex++ ;
    }

    if (can)
    {
        bool inc = true ;
        long res = 1 ;
        for (long i = firstindex+1 ; i < n ; i++)
        {
            if (inc)
            {
                if(inarr[i-1] < inarr[i])
                {
                    res++ ;
                    inc = !inc ;
                }
            }
            else
            {
                if(inarr[i-1] > inarr[i])
                {
                    res++ ;
                    inc = !inc ;
                }
            }

        }
        std::cout << res ;
    }
    else
    {
        std::cout << 0 ;
    }

}
