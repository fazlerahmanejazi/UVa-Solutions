#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int T, N, cases=1, ans, t, c ;
    cin>>T ;
    while(T--)
    { ans= 0 ;
        t= 0 ;
        cin>> N ;
        vector<char> a(N+1) ;
        for(int i=0 ; i<N ; i++)
        {
            cin>> a[i] ;
        }
        c=0 ;
        a[N]='*' ;
        for(int i=0 ; i<N ; i++)
        {
            if(a[i]=='.')
            { t++ ;
                c++ ;
                if(c==1)
                {
                    if(a[i+1]=='#')
                    {
                        ans++ ;
                        c=0 ;
                        i=i+2 ;
                        t=0 ;

                    }
                }
                else if(c==2)
                {
                    ans++ ;
                    i++ ;
                    c=0 ;
                    t=0 ;
                }

            }
            else
            { t=0 ;
                if(c==1)
                { i++ ;
                    ans++ ;
                    c=0 ;
                }
            }
        }
        if(t%3==1) ans++ ;
        cout<< "Case "<< cases << ": " << ans << endl ;
        cases++ ;
    }
    return 0 ;
}
