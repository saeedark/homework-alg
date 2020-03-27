#include <iostream>

void prn(int * l, int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        std::cout << l[i] << " " ; 
    }
    std::cout << std::endl ;
}
void lastMerge(int* indexlist ,int* v , int f , int m , int e , int* l )
{
    indexlist[0] = 0 ;
    int indexlisti = 1 ;
    int vtmp[e - f + 1] ;
    int ltmp[e - f + 1] ;
    for (int i = f ; i < e + 1 ; i++) 
    {
       vtmp[i-f] = v[i] ;  
       ltmp[i-f] = l[i] ;  
    }
    int li = f ;
    int ri = m + 1 ;
    int i = f ;
    
    while( li < m+1 && ri < e+1 )
    {
        if (vtmp[li-f] <= vtmp[ri-f])
        {
        if(i-1>=f)
        {
            if (v[i-1] != vtmp[li-f])
            {
                indexlist[indexlisti] = i ;
                indexlisti++ ;
            }
        }
            v[i] = vtmp[li-f] ;
            l[i] = ltmp[li-f] ;
            i++ ;
            li++ ;
        }
        else
        {
        if(i-1>=f)
        {
            if (v[i-1] != vtmp[ri-f])
            {
                indexlist[indexlisti] = i ;
                indexlisti++ ;
            }
        }
            v[i] = vtmp[ri-f] ;
            l[i] = ltmp[ri-f] ;
            i++ ;
            ri++ ;
        }
    }
    
    while (li < m+1)
    {
        if (v[i-1] != vtmp[li-f])
        {
            indexlist[indexlisti] = i ;
            indexlisti++ ;
        }
        v[i] = vtmp[li-f] ;
        l[i] = ltmp[li-f] ;
        i++ ;
        li++ ;
    }
    while (ri < e+1)
    {
        if (v[i-1] != vtmp[ri-f])
        {
            indexlist[indexlisti] = i ;
            indexlisti++ ;
        }
        v[i] = vtmp[ri-f] ;
        l[i] = ltmp[ri-f] ;
        i++ ;
        ri++ ;
    }
    
    indexlist[indexlisti] = -1 ;

}
void mergeSortMerge(int* v , int f , int m , int e , int* l)
{
    int vtmp[e - f + 1] ;
    int ltmp[e - f + 1] ;
    for (int i = f ; i < e + 1 ; i++) 
    {
       vtmp[i-f] = v[i] ;  
       ltmp[i-f] = l[i] ;  
    }
    int li = f ;
    int ri = m + 1 ;
    int i = f ;
    while( li < m+1 && ri < e+1 )
    {
        if (vtmp[li-f] <= vtmp[ri-f])
        {
            v[i] = vtmp[li-f] ;
            l[i] = ltmp[li-f] ;
            i++ ;
            li++ ;
        }
        else
        {
            v[i] = vtmp[ri-f] ;
            l[i] = ltmp[ri-f] ;
            i++ ;
            ri++ ;
        }
    }
    while (li < m+1)
    {
        v[i] = vtmp[li-f] ;
        l[i] = ltmp[li-f] ;
        i++ ;
        li++ ;
    }
    while (ri < e+1)
    {
        v[i] = vtmp[ri-f] ;
        l[i] = ltmp[ri-f] ;
        i++ ;
        ri++ ;
    }
}
void mergeSort(int* v , int f , int e , int* l )
{
    if (f < e)
    {
    int m = f + ( ( e - f ) / 2 ) ;
    mergeSort(v , f , m , l) ;
    mergeSort(v , m + 1 , e , l) ;
    mergeSortMerge(v , f , m , e , l);
    }
}
int sameSpeedsort(int* l , int f , int e)
{
    int res = 0 ;
    if (f == e)
    {
        return 0 ;
    }
    if ( e-f == 1 )
    {
        if (l[e] < l[f])
        {
            l[e] = l[f] + l[e] ;
            l[f] = l[e] - l[f] ;
            l[e] = l[e] - l[f] ;
        }
        return l[e] - l[f] ;
    }
    int m = f + (e-f)/2 ;
    res += sameSpeedsort(l , f , m);
    res += sameSpeedsort(l , m+1 ,e);
    int tmpr[e-m] ;
    int tmpl[m-f+1] ;
    /* ToDo : two folling for can be combine  */
    for (int i = 0 ; i < m-f+1 ; i++)
    {
        tmpl[i] = l[f+i] ;
    }
    for (int i = 0 ; i < e-m ; i++)
    {
        tmpr[i] = l[m+1+i] ;
    }
    int mri = 0 ;
    int mli = 0 ;
    int rn = 0 ;
    int ln = 0 ;
    int lastl = 0 ;
    int lastr = 0 ;
    int vl = 0 ;
    int vr = 0 ;
    int mi = f ;
    while (mri < e-m && mli < m-f+1 )
    {
    if(tmpl[mli] < tmpr[mri])
    {
        if (lastr == mri)
        {
            res += tmpr[mri] -tmpl[mli] ;
            vr += tmpr[mri] - tmpl[mli] ;
            ln += 1 ;
        }
        else
        {
            res += tmpr[mri] - tmpl[mli] ;
            res += (tmpr[mri] - tmpr[lastr])*ln + vr ;
            vr += tmpr[mri] - tmpl[mli] + (tmpr[mri] - tmpr[lastr])*ln ;
            ln += 1 ;
            lastr = mri ;
            
        }
        if (lastl != mli)
        {
            res += (tmpl[mli] - tmpl[lastl])*rn + vl ;
            vl += (tmpl[mli] - tmpl[lastl])*rn ;
            lastl = mli ;
        }
        l[mi] = tmpl[mli] ;
        mli++ ;
    }
    else
    { 
        if (lastl == mli)
        {
            res += tmpl[mli] - tmpr[mri] ;
            vl += tmpl[mli] - tmpr[mri] ;
            rn += 1 ;
        }
        else
        {
            res += tmpl[mli] - tmpr[mri] ;
            res += (tmpl[mli] - tmpl[lastl])*rn + vl ;
            vl += tmpl[mli] - tmpr[mri] + (tmpl[mli] - tmpl[lastl])*rn ;
            rn += 1 ;
            lastl = mli ;
            
        }
        if (lastr != mri)
        {
            res += (tmpr[mri] - tmpr[lastr])*ln + vr ;
            vr += (tmpr[mri] - tmpr[lastr])*ln ;
            lastr = mri ;
        }
        l[mi] = tmpr[mri];
        mri++ ;
    }
    mi++ ;  
    }
    while (mri < e-m)
    {   
        if (lastr == mri)
        {
        }
        else
        {
            res += (tmpr[mri] - tmpr[lastr])*ln + vr ;
            
        }
        l[mi] = tmpr[mri] ;
        mi++ ;
        mri++ ;
    }
    
    
    while (mli < m-f+1)
    {
        if (lastl == mli)
        {
        }
        else
        {
            res += (tmpl[mli] - tmpl[lastl])*rn + vl ;
            
        }
        l[mi] = tmpl[mli] ;
        mi++ ;
        mli++ ;
    }

    return res ;
}
int difSpeedsort(int* l , int fi , int si , int e)
{
    int res = 0 ;
    int tmpl[si-fi] ;
    int tmpr[e-si+1] ;
    for (int i = 0 ; i < si-fi ; i++)
    {
        tmpl[i] = l[fi+i];
    }
    for (int i = 0 ; i < e-si+1 ; i++)
    {
        tmpr[i] = l[si+i];
    }
   
    int li = 0 ;
    int ri = 0 ;
    int mi = fi ;
    int pr = 0 ;
    int ln = 0 ;
    int vr = 0 ;
    while (li < si-fi && ri < e-si+1)
    {
        if (tmpl[li] < tmpr[ri])
        {
            if (pr == ri)
            {
                vr += tmpr[ri] - tmpl[li] ;
                res += tmpr[ri] - tmpl[li] ;
                ln++ ;
            }
            else
            {
                res += tmpr[ri] - tmpl[li] + vr + (tmpr[ri]-tmpr[pr])*ln ;
                vr += tmpr[ri] - tmpl[li] ;
                vr = vr + (tmpr[ri]-tmpr[pr])*ln ;
                pr = ri ;
                ln++ ;
            }
            l[mi] = tmpl[li] ;
            li++ ;
        }
        else
        {
            if (pr == ri)
            {
            }
            else
            {
                res += vr + (tmpr[ri]-tmpr[pr])*ln ;
                vr += (tmpr[ri]-tmpr[pr])*ln ;
                pr = ri ;
            }
            l[mi] = tmpr[ri] ;
            ri++ ;
        }
        mi++ ;
    } 

    while (li < si-fi)
    {
        l[mi] = tmpl[li] ;
        li++ ;
        mi++ ;
    }

    while (ri < e-si+1)
    {
        if (pr != ri)
        {
        res += vr + (tmpr[ri]-tmpr[pr])*ln ;
        }
        l[mi] = tmpr[ri] ;
        ri++ ;
        mi++ ;
    }

    return res ;
}
int main()
{
    int n ;
    std::cin >> n ;
    int Location[n] ;
    int Velocity[n] ;
    int indexlist[n+1] ; //making massive memoryLost here, don't wanna dynamic memory just 
    int m = n / 2 ;
    int result = 0 ;
    int fss = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        std::cin >> Location[i] ;
    }
    for (int i = 0 ; i < n ; i++)
    {
        std::cin >> Velocity[i] ;
    }
    mergeSort(Velocity , 0 , m-1 , Location) ;
    mergeSort(Velocity , m  , n - 1 , Location) ;
    lastMerge(indexlist , Velocity , 0 , m-1 , n-1 , Location ) ;
    int lstnon = 1 ;
    for (int i = 1 ; indexlist[i] != -1 ; i++)
    {
        result += sameSpeedsort(Location , fss, indexlist[i]-1) ;
        fss  = indexlist[i] ;
        lstnon = i ;
    }
    lstnon++ ;
    result += sameSpeedsort(Location , fss , n-1) ;
    int b = 1 ;
    int ii = 0 ;
    while (indexlist[1] != -1 && indexlist[2] != -1)
    {
        b = 1 ;
        ii = 0 ;
        for(int i = 2 ; i < lstnon ; i+=2)
        {
            result += difSpeedsort(Location , indexlist[i-2] , indexlist[i-1] , indexlist[i]-1) ;
            indexlist[b] = indexlist[i] ;
            ii = i ;
            b++ ;
        }
        if (indexlist[ii] == -1 && ii == lstnon )
        {
            result += difSpeedsort(Location , indexlist[ii-2] , indexlist[ii-1] , n-1) ;
            indexlist[b] = -1 ;
            b++ ;
        }
        else
        {
            if (indexlist[ii-1] == -1 && lstnon >= ii-1)
            {
                indexlist[b] = indexlist[ii-2] ;
                b++ ;
            }
        }
        if(b!=1)
        {
        indexlist[b] = -1 ;
        }
        lstnon = b ;
    } 
    if (indexlist[2] == -1 )
    {
        result += difSpeedsort(Location , indexlist[0] , indexlist[1] , n-1) ;
        indexlist[b] = -1 ;
        b++ ;
    }
    std::cout << result ;

}
