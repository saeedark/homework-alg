/* Order in algorithm O(n) e chon ke
 * 1 bar for mizanim ro inputemonn va har inputemoon
 * ro nahayat ba 4 taye kenari chek mikonim 
 * ke mishe 4n
 */
#include <iostream>

bool av(int i , int j , int n)
{
	bool iav = (i < n) && (-1 < i) ;
	bool jav = (j < n) && (-1 < j) ;
	return jav*iav ;
}


int main()
{
	int n = 0 ;
	std::cin >> n ;
	int tb[n][n] ;
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
				std::cin >> tb[i][j] ;
		}
	}
	int ri = 0 ;
	int rj = 0 ;
	bool br = 0 ;
	for (int i = 0 ; i < n ; i++ )
	{
		if (br) break ;
		for (int j = 0 ; j < n ; j++)
		{
			bool ihm = true ;
			if (av(i-1,j,n))
			{
				ihm&=(tb[i][j]>tb[i-1][j]) ;
			}
			if (av(i+1,j,n)) 
			{
				ihm&=(tb[i][j]>tb[i+1][j]) ;
			}
			if (av(i,j+1,n))
			{
				ihm&=(tb[i][j]>tb[i][j+1]) ;
			}
			if (av(i,j-1,n)) 
			{
				ihm&=(tb[i][j]>tb[i][j-1]) ;
			}
			if(ihm)
			{
				ri = i ;
				rj = j ;
				br = 1 ;
				break ;
			}
		}
	}
	std::cout << ri*n+rj+1 << " " << tb[ri][rj] ;
}
