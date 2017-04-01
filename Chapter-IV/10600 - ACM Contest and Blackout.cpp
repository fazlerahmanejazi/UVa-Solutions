#include <bits/stdc++.h>
using namespace std ;

int n, m, T, a, b, w, ans, check, k, res, tot ;
vector<pair<int, pair<int, int> > > edge ;
pair<int, pair<int, int> > temp ;
vector<bool> mst ;

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
      cin>> n >> m ;
      edge.clear() ;
      mst.clear() ;
      ans=0 ;
      check=0 ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> a >> b >> w ;
          edge.push_back(make_pair(w, make_pair(a, b))) ;
        }
      sort(edge.begin(), edge.end()) ;
      mst.assign(m, false) ;
      UnionFind graph(n+1) ;
      for(k=0 ; k<m ; k++)
        {
          temp=edge[k] ;
          if(!graph.same(temp.second.first, temp.second.second))
            {
              ans+=temp.first ;
              mst[k]=true ;
              graph.unionset(temp.second.first, temp.second.second) ;
            }
        }
      res=10000000 ;
      for(int i=0 ; i<m ; i++)
        {
          tot=0 ;
          check=0 ;
          if(mst[i])
          {
            UnionFind graph(n+1) ;
            for(int j=0 ; j<m ; j++)
              {
                temp=edge[j] ;
                if(j==i) continue ;
                if(!graph.same(temp.second.first, temp.second.second))
                  {
                    tot+=temp.first ;
                    graph.unionset(temp.second.first, temp.second.second) ;
                    check++ ;
                  }
              }
          }
          if(check==n-1) res=min(tot, res) ;
        }
      cout<< ans << " " << res << endl ;
    }
}
