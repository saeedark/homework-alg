/* 
 * sadeghane in algorithm be zehene khodam neyomad vali bache ha goftan ke manzor az O(n)
 * n e ke aval dade mishe na tedad vorodi pas code ghabli ghalat bod
 * in ro didam 
 * https://www.youtube.com/watch?feature=player_embedded&v=P7frcB_-g4w  
 * akharesh mige ke mitonim ba peyda kardan peak dar 
 * matrix binaray search bezanid dar ye col man dar row mizanam 
 * va beyde row ham binary search pas mishe logm * logn ke inja m o n yeki dar natije order n e
 * albate linke zire ro ham didam ke taghsim be 4 baghsh mikone
 * http://kamalmeet.com/algorithms/finding-a-peak-in-2-dimensional-array/
 * va esbatesh in tory bod ke
 * T(n) = T(n/2) + n
 * T(n) = (n/4) + n/2 + n
 * ke dar nahayat mishe 1 + 2+ 4 + ... + n/4 + n/2 + n
 * ama jame ghable n be n nemirese pas order az O(n)
 * hast
 *
 */



#include <iostream>
int access(int *inputlist , int i , int j , int n)
{
    return inputlist[i*n+j] ;
}
int findarrpeak(int * inputlist , int n , int row , int fi , int li)
{
    if (li - fi == 1)
    {
        return (access(inputlist , row , fi , n) > access(inputlist , row , li , n) ? fi : li) ;
    }
    int m = fi + (li - fi)/2 ;
    if (access(inputlist , row , m , n) < access(inputlist , row , m-1 , n))
    {
        return findarrpeak(inputlist , n , row , fi , m) ;
    }
    if (access(inputlist , row , m , n) < access(inputlist , row , m+1 , n))
    {
        return findarrpeak(inputlist , n , row , m ,li) ;
    }
    return m ;
}
bool ispeak(int * inputlist ,int n ,int  row ,int i)
{
    bool res = true ;
    if (row-1 > -1)
    {
        res &= (access(inputlist ,row , i , n) >= access(inputlist ,row-1 , i ,n)) ;
    }
    if (row+1 < n)
    {
        res &= (access(inputlist ,row , i , n) >= access(inputlist ,row+1 , i ,n)) ;
    }
    return res ;
}
int main()
{
    int n ;
    std::cin >> n ;
    int inputlist[n][n] ;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            std::cin >> inputlist[i][j] ;
        }
    }
    int firstrow = 0 ;
    int lastrow = n-1 ;
    int m ;
    int midrowpicki ;
    while (lastrow != firstrow)
    {
        m = firstrow + (lastrow - firstrow)/2 ;
        midrowpicki = findarrpeak(*inputlist , n , m , 0 , n-1) ;
        if (ispeak(*inputlist , n , m ,midrowpicki))
        {
            firstrow = m ;
            break ;
        }
        if (access(*inputlist, m , midrowpicki, n) < access(*inputlist, m-1 , midrowpicki, n))
        {
        lastrow = m-1 ;
        }
        else
        {
        firstrow = m+1 ;
        }
    }
    midrowpicki = findarrpeak(*inputlist , n , firstrow  , 0 , n-1) ;
    std::cout << firstrow*n+midrowpicki+1 << " " << access(*inputlist , firstrow ,midrowpicki  ,n) ;
}
