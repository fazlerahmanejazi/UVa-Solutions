#include <bits/stdc++.h>
using namespace std ;

int n, T, w, ans ;
char a, b ;
string s ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  getline(cin, s) ;
  getline(cin, s) ;
  s="" ;
  while(T--)
    {
      n=0 ;
      cout<< s ;
      vector<vector<int> > adj(27) ;
      vector<int> weight(27) ;
      vector<int> dist(27) ;
      ans=0 ;
      while(getline(cin, s) && s!="")
        {
          n++ ;
          stringstream ss(s);
          ss>> a >> w ;
          weight[a-'A']=w ;
          while(ss>>b) adj[b-'A'].push_back(a-'A') ;
        }
      for(int i=0 ; i<n ; i++)
      	dist[i]=weight[i] ;
      for(int i=0 ; i<n-1 ; i++)
        {
          for(int j=0 ; j<n ; j++)
            {
              for(int k=0 ; k<adj[j].size() ; k++)
                {
                  if(dist[adj[j][k]]<dist[j]+weight[adj[j][k]])
                    {
                    	dist[adj[j][k]]=dist[j]+weight[adj[j][k]] ;
                    }
                }
            }
        }
      for(int i=0 ; i<n ; i++)
        if(adj[i].size()==0)
          ans=max(ans, dist[i]) ;
      cout<< ans << endl ;
      s='\n' ;
    }
  return 0 ;
}
