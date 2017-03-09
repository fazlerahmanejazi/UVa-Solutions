#include <bits/stdc++.h>
using namespace std ;

int n, T, c, s ;
string a, b ;

class UnionFind
  {
    private: vector<int> rank, p ;
    public:
      vector<int> size ;
      UnionFind(int n)
        {
          rank.assign(n, 0) ;
          p.assign(n, 0) ;
          size.assign(n, 1) ;
          for(int i=0 ; i<n ; i++) p[i]=i ;
        }
      int find(int i)
        {
          if(i!=p[i])
            p[i]=find(p[i]) ;
          return p[i] ;
        }
      bool same(int i, int j) {return find(i)==find(j) ;}
      void unionset(int i, int j)
        {
          if(!same(i,j))
            {
              int x=find(i) ; int y=find(j) ;
              if(rank[x]>rank[y])
                {
                  p[y]=x ;
                  size[x]+=size[y] ;
                }
              else
                {
                  p[x]=y ;
                  if(rank[x]==rank[y]) rank[y]++ ;
                  size[y]+=size[x] ;
                }
            }
        }
  } ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  while(T--)
    {
      cin>> n ;
      map<string, int> cnc ;
      map<string, bool> check ;
      UnionFind Virtual(100000) ;
      c=0 ;
      for(int i=0 ; i<n ; i++)
        {
          cin>> a >> b ;
          if(!check[a]) { cnc[a]=c++ ; check[a]=true ;}
          if(!check[b]) { cnc[b]=c++ ; check[b]=true ;}
          Virtual.unionset(cnc[a], cnc[b]) ;
          s=Virtual.find(cnc[b]) ;
          cout<< Virtual.size[s] << endl ;
        }
    }
  return 0 ;
}
