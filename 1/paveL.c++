#include "iostream"


int arrayIndex(int c , int i ,int j)
{
	return j+i*c ;
}


void Prn(int * inp , int n )
{
	for (int i = 0 ; i < n ; i++)
	{
		std::cout << "\n" ;
		for (int j = 0 ; j < n ; j++)
		{
			std::cout << inp[arrayIndex(n , i , j)] << "     " ;
		}
	}
}

int DeleteLocation(int fi , int li , int fj , int lj , int di , int dj)
{
	bool ri = false ;
	bool rj = false ;
	if ( di  > fi -1  + (1+li-fi)/2 )
	{
		ri = true;
	}
	if ( dj  > fj -1 + (1+lj-fj)/2 )
	{
		rj = true;
	}

	return 2*rj+ri ; /* 0 - 1 up / down 2 - 3 */
}

void pave(int* inp, int fi , int li , int fj, int lj ,int di , int dj , int  fn , int ln , int n )
{
    if ( (1+li-fi) == 2 )
	{
	for (int i = 0 ; i < 2 ; i++)
	{
		for (int j = 0 ; j < 2 ; j++)
		{
			if (inp[arrayIndex(n,i+fi,j+fj)] == 0)
			{
			inp[arrayIndex(n,i+fi,j+fj)] = fn ;
			}
		}
	}
	}else
	{
	int where = DeleteLocation(fi , li , fj , lj , di , dj);
	switch (where)
	{
		case 0 :
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)  ,fj +  int((lj-fj+1)/2)-1)] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)-1,fj +  int((lj-fj+1)/2)  )] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)  ,fj +  int((lj-fj+1)/2)  )] = fn ;
		    pave(inp,  fi                    , fi + int((li-fi+1)/2)-1 , fj                     ,fj +  int((lj-fj+1)/2)-1  ,    di                   ,    dj                    ,   fn+1                 ,  fn + int((ln-fn)/4)   ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) ,  li                     , fj                     , fj +  int((lj-fj+1)/2)-1 , fi + int((li-fi+1)/2)   , fj +  int((lj-fj+1)/2)-1 ,fn + int((ln-fn)/4) + 1 , fn + 2*int((ln-fn)/4)  ,   n);
		    pave(inp, fi                     , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2) , lj                       , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2)   ,fn+ 2*int((ln-fn)/4) +1 , fn + 3*int((ln-fn)/4)  ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) , li                      , fj +  int((lj-fj+1)/2) , lj                       , fi + int((li-fi+1)/2)   , fj +  int((lj-fj+1)/2)   ,fn+ 3*int((ln-fn)/4) +1 , ln                     ,   n);
		    break ;
		case 1 :
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)-1,fj +  int((lj-fj+1)/2)-1)] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)-1,fj +  int((lj-fj+1)/2)  )] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)  ,fj +  int((lj-fj+1)/2)  )] = fn ;
		    pave(inp,  fi                    , fi + int((li-fi+1)/2)-1 , fj                     ,fj +  int((lj-fj+1)/2)-1  , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2)-1 ,   fn+1                 ,  fn + int((ln-fn)/4)   ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) ,  li                     , fj                     , fj +  int((lj-fj+1)/2)-1 , di                      , dj                       ,fn + int((ln-fn)/4) + 1 , fn + 2*int((ln-fn)/4)  ,   n);
		    pave(inp, fi                     , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2) , lj                       , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2)   ,fn+ 2*int((ln-fn)/4) +1 , fn + 3*int((ln-fn)/4)  ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) , li                      , fj +  int((lj-fj+1)/2) , lj                       , fi + int((li-fi+1)/2)   , fj +  int((lj-fj+1)/2)   ,fn+ 3*int((ln-fn)/4) +1 , ln                     ,   n);
		    break ;
		case 2 :
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)-1,fj +  int((lj-fj+1)/2)-1)] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)  ,fj +  int((lj-fj+1)/2)-1)] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)  ,fj +  int((lj-fj+1)/2)  )] = fn ;
		    pave(inp,  fi                    , fi + int((li-fi+1)/2)-1 , fj                     ,fj +  int((lj-fj+1)/2)-1  , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2)-1 ,   fn+1                 ,  fn + int((ln-fn)/4)   ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) ,  li                     , fj                     , fj +  int((lj-fj+1)/2)-1 , fi + int((li-fi+1)/2)   , fj +  int((lj-fj+1)/2)-1 ,fn + int((ln-fn)/4) + 1 , fn + 2*int((ln-fn)/4)  ,   n);
		    pave(inp, fi                     , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2) , lj                       , di                      , dj                       ,fn+ 2*int((ln-fn)/4) +1 , fn + 3*int((ln-fn)/4)  ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) , li                      , fj +  int((lj-fj+1)/2) , lj                       , fi + int((li-fi+1)/2)   , fj +  int((lj-fj+1)/2)   ,fn+ 3*int((ln-fn)/4) +1 , ln                     ,   n);
		    break ;
		case 3 :
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)-1,fj +  int((lj-fj+1)/2)-1)] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)  ,fj +  int((lj-fj+1)/2)-1)] = fn ;
		    inp[arrayIndex(n ,fi + int((li-fi+1)/2)-1,fj +  int((lj-fj+1)/2)  )] = fn ;
		    pave(inp,  fi                    , fi + int((li-fi+1)/2)-1 , fj                     ,fj +  int((lj-fj+1)/2)-1  , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2)-1 ,   fn+1                 ,  fn + int((ln-fn)/4)   ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) ,  li                     , fj                     , fj +  int((lj-fj+1)/2)-1 , fi + int((li-fi+1)/2)   , fj +  int((lj-fj+1)/2)-1 ,fn + int((ln-fn)/4) + 1 , fn + 2*int((ln-fn)/4)  ,   n);
		    pave(inp, fi                     , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2) , lj                       , fi + int((li-fi+1)/2)-1 , fj +  int((lj-fj+1)/2)   ,fn+ 2*int((ln-fn)/4) +1 , fn + 3*int((ln-fn)/4)  ,   n);
		    pave(inp,  fi + int((li-fi+1)/2) , li                      , fj +  int((lj-fj+1)/2) , lj                       , di                      , dj                       ,fn+ 3*int((ln-fn)/4) +1 , ln                     ,   n);
		    break ;
	}
	
	}
}



int main()
{
	int n,i,j;
	std::cin >> n >> j >> i ;

	int paves [n][n];
	for (int i = 0 ; i < n ; i++)
	{
	    for (int j = 0 ; j < n ; j++)
	    {
		paves[i][j] = 0 ;
	    }
	}
	int fn = ((n*n)-1)/3;
	paves[i][j] = fn + 1 ; 
	pave(*paves , 0 , n-1 , 0 , n-1 , i , j , 1 , fn , n);
	Prn(*paves,n);
}
