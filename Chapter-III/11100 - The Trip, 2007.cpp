#include <bits/stdc++.h>
using namespace std ;

int main()
{ int N,temp, m, j, r  ;
    while(cin>>N && N!=0)
    { vector<int> a(N) ;

        for(int i=0 ; i<N ; i++)
            cin>> a[i] ;

        sort(a.begin(), a.end()) ;
        r=1 ;
        m=1 ;
        for(int i=1 ; i<N ; i++)
        {
            if(a[i]==a[i-1]) {r++ ; if(r>m) m=r ;}
            else r=1 ;
        }
        m = max(m, r);
       cout<< m << endl ;

        for(int i=0; i<m; i++)
         {
             int f = 1;
             for(int j=i; j<N; j+=m)
              {
                 if(!f) cout<< " " ;
                 cout<< a[j] ;
                 if(f) f = 0;
             }
             cout<< endl ;
         }
    }
    return 0 ;
}
