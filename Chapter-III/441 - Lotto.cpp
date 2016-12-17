#include <bits/stdc++.h>
using namespace std ;

int k, temp, j=1 ;
vector<int> a(k) ;
vector<int> ans(k) ;
vector<int> taken(50, 1) ;

void add(int T)
{
  if(ans.size()==6)
  {
    for(int i=0; i<6; i++)
     {
        cout<< ans[i] ;
        if(i<5)
        cout<< " " ;
     }
    cout<< endl ;
    return ;
  }
  else
  {
    for(int i=T ; i<k ; i++)
    {
        ans.push_back(a[i]) ;
        add(i+1) ;
        ans.pop_back() ;
    }
  }
}

int main()
{ ios_base::sync_with_stdio (false) ;
  while(cin>> k && k)
  { a.clear() ; ans.clear() ;
    if(j>1) cout<< endl ;
     for(int i=0 ; i<k ; i++)
    {
      cin>> temp ;
      a.push_back(temp) ;
      taken[temp]=0 ;
    }
    add(0) ;
    j++ ;
  }
return 0 ;
}
