#include <bits/stdc++.h>
using namespace std ;

int adj[205][205] ;
string a, b;
int ans, c, n, m, T ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    T=1 ;
    while(cin>>n && n)
      {
        map<int, string> ncn ;
        map<string, int> cnc;
        for(int i = 0; i < 205; i++)
            for(int j = 0; j < 205; j++)
                adj[i][j] = 0;
        c=0 ;
        for(int i = 0; i < n; i++)
          {
            cin>> m ;
            int w = c;
            for(int j=0 ; j<m ; j++)
              {
                cin >> a;
                cnc[a] = c, ncn[c]=a ;
                c++;
              }
            for(int j=w ; j<c-1 ; j++)
                adj[j][j+1] = 1;
          }
        cin>> m ;
        for(int j=0 ; j<m ; j++)
          {
            cin >> a >> b;
            adj[cnc[a]][cnc[b]] = 1;
          }
        for(int k=0 ; k<c; k++)
            for(int i=0; i<c; i++)
                for(int j=0; j<c; j++)
                    adj[i][j] |= adj[i][k]&adj[k][j];

        a = "";
        ans=0 ;
        for(int i=0; i<c; i++)
            for(int j=i+1 ; j<c ; j++)
                if(adj[i][j] == 0 && adj[j][i] == 0)
                  {
                    ans++;
                    if(ans <= 2)
                        a+="("+ncn[i]+","+ncn[j]+") ";
                  }
        if(ans)
            {
               cout<< "Case "<< T++ <<", "<< ans <<" concurrent events:" << endl ;
               cout<< a << endl ;
            }
        else cout<< "Case "<< T++ << ", no concurrent events." << endl ;
    }
    return 0;
}
