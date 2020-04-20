#include <iostream>

void prn(int a[],int n)
{
    std::cout << "\n" ;
    for ( int i = 0 ; i < n ; i++ )
    {
        std::cout << a[i] << " " ;
    }
    std::cout << "\n" ;
}

int main()
{
    int n ;
    int k ;
    int m ;
    int res = 0 ;

    std::cin >> n >> k >> m ;

    int keys[k] ;
    int balls[m] ;
    int locks[n+1] ;

    /* -1 = empty , 0 = key , 1 = ball , 2 = open */

    for (int i = 0 ; i < n+1 ; i++)
    {
        locks[i] = -1 ;
    }
    int kn = k ;
    for (int i = 0 ; i < k ; i++)
    {
        std::cin >> keys[i] ;
        if (locks[keys[i]] != -1)
        {
            kn--;
        }
        else
        { 
        locks[keys[i]]++ ;
        }
    }
    k = kn ;
    for (int i = 0 ; i < m ; i++)
    {
        std::cin >> balls[i] ;
        if (locks[balls[i]] == -1)
        {
            locks[balls[i]] = 1 ;
        }
        else if (locks[balls[i]] == 0 )
        {
            locks[balls[i]] = 2 ;
            res++ ;
        }
    }
   
    //
    std::cout << " k  " << k << " res " << res << " \n " ;
    prn(locks,n+1) ;
    

    int firstkey = 0 ;
    int stcount = false ;
    while (locks[firstkey] != 0 && locks[firstkey] != 2)
    {
        if(locks[firstkey] == 1)
        {
            stcount = true ;
        }
        if (stcount)
        {
            res++ ;
        }
        firstkey++;
    }
    if (stcount)
    {
        res++ ;
        if (locks[firstkey] == 2)
        {
            res-- ;
        }
        locks[firstkey] = 2 ;
    }
    k-- ;
   
    //
    std::cout << " rez : " << res << "\n" ;

    int diff ;
    int ldiff ;
    int maxdiff ;
    int tmpres ;
    bool firstball ;
    
    while (k != 0 )
    {
        //
        std::cout << " rez : " << res << " k:  " << k << " firstkey: " << firstkey << "\n" ;
        
        diff = 0 ;
        ldiff = 0 ;
        maxdiff = 0 ;
        tmpres = 0 ;
        firstball = true ;
        for (int i = firstkey ; i < n+1 ; i++)
        {
            if (locks[i] == -1 )
            {
                diff++ ;
                tmpres++ ;
            }
            else if (locks[i] == 1)
            {
                tmpres++ ;
                if (firstball == true )
                {
                    ldiff = diff ;
                    firstball = false ;
                }
                maxdiff = (maxdiff > diff) ? maxdiff : diff ;
                diff = 0 ;
            }
            else if (locks[i] == 0)
            {
                if (firstkey != i)
                {
                    tmpres++ ;
                    diff++ ;
                    maxdiff = (maxdiff > diff) ? maxdiff : diff ;
                    //std::cout << " maxdif " << maxdiff  << " diff " << diff << " ldiff " << ldiff << " tmpres " << tmpres << "\n" ;
                    if ( (maxdiff == ldiff && ldiff >= diff && tmpres!=diff) || maxdiff > diff ) 
                    {
                        locks[i] = 2 ;
                    }
                    tmpres -= maxdiff ;
                    diff = 0 ;
                    maxdiff = 0 ;
                    firstkey = i ;
                    res += tmpres ;
                    tmpres = 0 ;
                    break ;
                }
                else
                {
                    tmpres++ ;
                    diff++ ;
                    maxdiff = (maxdiff > diff) ? maxdiff : diff ;
                }
            }
            else if (locks[i] == 2)
            {
                if (firstkey != i)
                {
                    maxdiff = (maxdiff > diff) ? maxdiff : diff ;
                    tmpres -= maxdiff ;
                    diff = 0 ;
                    maxdiff = 0 ;
                    firstkey = i ;
                    res += tmpres ;
                    tmpres = 0 ;
                    break ; 
                }
            }
        }
        k-- ;
    }

    //
    std::cout << " rez : " << res << " k:  " << k << " firstkey: " << firstkey << "\n" ;
    
    prn(locks,n+1);

    diff = 0 ;
    if ( locks[firstkey] == 0 )
    {
        diff++ ;
    }
    for (int i = firstkey + 1 ; i < n+1 ; i++)
    {
        diff++ ;
        if (locks[i] == 1)
        {
            res += diff ;
            std::cout << "diff " << diff << " res " << res << "\n" ;
            diff = 0 ;
        }
    }

    std::cout << res ;
}
