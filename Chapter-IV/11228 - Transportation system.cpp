#include <bits/stdc++.h>
using namespace std ;

int n, r, T, a, b, num, x, y, X, Y, check ;
double w, road, rail ;
vector<pair<double, pair<int, int> > > edge ;
pair<double, pair<int, int> > temp ;
vector<double> ans ;
vector<pair<int, int> > point ;

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
  for(int tc=1 ; tc<=T ; tc++)
    {
      cin>> n >> r ;
      edge.clear() ;
      ans.clear() ;
      point.clear() ;
      rail=road=check=0 ;
      num=1 ;
      for(int i=0 ; i<n ; i++)
        {
          cin>> a >> b ;
          point.push_back(make_pair(a, b)) ;
        }
      for(int i=0 ; i<n ; i++)
        {
          for(int j=i+1 ; j<n ; j++)
            {
              x=point[i].first ; y=point[i].second ;
              X=point[j].first ; Y=point[j].second ;
              w=sqrt((x-X)*(x-X)+(y-Y)*(y-Y)) ;
              edge.push_back(make_pair(w, make_pair(i, j))) ;
            }
        }
      sort(edge.begin(), edge.end()) ;
      UnionFind graph(n) ;
      for(int i=0 ; i<edge.size() ; i++)
        {
          temp=edge[i] ;
          if(!graph.same(temp.second.first, temp.second.second))
            {
              if(temp.first<=r) road+=temp.first ;
              else { rail+=temp.first ; num++ ;}
              graph.unionset(temp.second.first, temp.second.second) ;
              check++ ;
            }
          if(check==n-1) break ;
        }
      cout<< "Case #" << tc << ": " << num << " " << round(road) << " " << round(rail) << endl ;
    }
    return 0 ;
}
