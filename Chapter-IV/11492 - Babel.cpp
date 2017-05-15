#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
#define piic pair<pair<int, int>, char>

int T, n, c, u, v, d, ans ;
string a, b, s, t, w ;
char f, curr ;
vector<vector<piic > > adj ;
piic temp ;
int dist[5010][30] ;

int first(char &c)
  {
      if (c=='*') return 0 ;
      else return c-'a'+1;
  }

void dijkstra(int start)
  {
    priority_queue<piic , vector<piic> , greater<piic> > discovered ;
    discovered.push(make_pair(make_pair(0, start), '*')) ;
    for(int i=0 ; i<28 ; i++)
      dist[start][i]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.top() ;
        discovered.pop() ;
        u=temp.first.second ; d=temp.first.first ; curr=temp.second ;
        if(dist[u][first(curr)]<d) continue ;
        for(int i=0 ; i<adj[u].size() ; i++)
          {
            v=adj[u][i].first.first ; d=adj[u][i].first.second ; f=adj[u][i].second ;
            if(dist[u][first(curr)]+d<dist[v][f-'a'+1] && curr!=f)
              {
                dist[v][first(f)]=dist[u][first(curr)]+d  ;
                discovered.push(make_pair(make_pair(dist[v][first(f)], v), f)) ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>>n)
  {
    if(!n) break ;
    c=1 ;
    ans=inf ;
    cin>> s >> t ;
    map<string, int> cnc ;
    if(!cnc[s]) cnc[s]=c++ ;
    if(!cnc[t]) cnc[t]=c++ ;
    adj.clear() ;
    adj.resize(5010) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b >> w ;
        if(!cnc[a]) cnc[a]=c++ ;
        if(!cnc[b]) cnc[b]=c++ ;
        adj[cnc[a]].push_back(make_pair(make_pair(cnc[b], w.length()), w[0])) ;
        adj[cnc[b]].push_back(make_pair(make_pair(cnc[a], w.length()), w[0])) ;
      }
    for(int i=0 ; i<27 ; i++)
    	for(int j=0 ; j<c ; j++)
    		dist[j][i]=inf ;
    dijkstra(cnc[s]) ;
    for(int i=0 ; i<27 ; i++)
      ans=min(ans, dist[cnc[t]][i]) ;
    if(ans==inf || !ans) cout<< "impossivel" << endl ;
    else cout<< ans << endl ;
   }
   return 0 ;
 }
