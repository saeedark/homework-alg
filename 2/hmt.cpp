#include <iostream>

int main()
{
	int n = 0 ;
	std::cin >> n ;
	int p2[n+1] ;
	int t2[n+1] ;
	p2[0] = 1 ;
	t2[0] = 1 ;
	for (int i = 1 ; i < n+1 ; i ++)
	{
		p2[i] = 2*p2[i-1] ;
		t2[i] = t2[i-1] + p2[i] ;
	}
	int sl = 2*p2[n] - 1  ;
	int il[sl] ;
	bool lc[n-1] ;
	for (int i = 0 ; i < n-1 ; i++)
	{
		std::cin >> il[i] ;
		lc[i] = 0 ;
	}
	for (int i = n-1 ; i < sl ; i++)
	{
		std::cin >> il[i] ;
	}
	int p = 0 ;
	int i = 0 ; 
	int v = il[0] ; 
	int tpl = 0 ;
	int vtpl = 0 ;
	int tpr = 0 ;
	int vtpr = 0 ;
	bool ls = 0 ;
	bool rs = 0 ;
	for (int l = 0 ; l < n  ; l++)
	{
		tpl = t2[l] + p ;
		vtpl = il[tpl] ;
		tpr = tpl  + 1;
		vtpr = il[tpr] ;
		ls = ( v > vtpl) ;
		rs = ( v > vtpr) ;
		if ( ls )
		{
		}
		else
		{ /* childeren nodes never must have same value as parent one!!!*/
			i = tpl ;
			v = vtpl ;
			p = p*2 ;
			continue ;
		}
	
		if ( rs )
		{
			break ;
		}
		else
		{
			i = tpr ;
			v = il[tpr] ;
			p = p*2 ;
		}
	}
	std::cout << i+1 << " " << v ;
}
