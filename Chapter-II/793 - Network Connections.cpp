#include <bits/stdc++.h>
using namespace std ;

int n, T, succ, unsucc, a, b ;
char c, x, y ;

class UnionFind
  {
    private: vector<int> rank, p ;
    public:
      UnionFind(int n)
        {
          rank.assign(n, 0) ;
          p.assign(n, 0) ;
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
                }
              else
                {
                  p[x]=y ;
                  if(rank[x]==rank[y]) rank[y]++ ;
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
      succ=0 ;
      unsucc=0 ;
      UnionFind network(n+1) ;
      string s ;
      getline(cin, s);
      while(getline(cin, s), s!="")
        {
          stringstream ss(s);
          ss >> c >> a >> b ;
          if(c=='c') network.unionset(a,b) ;
          else
            {
              if(network.same(a,b)) succ++ ;
              else unsucc++ ;
            }
        }
      cout<< succ << "," << unsucc << endl ;
      if(T!=0) cout<< endl ;

    }
  return 0 ;
}
