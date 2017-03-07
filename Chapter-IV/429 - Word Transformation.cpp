#include <bits/stdc++.h>
using namespace std ;

int T, n, t ;
string temp, s, e, c ;
vector<string> dict ;
vector<vector<int> > adj ;

int bfs(int start, int end)
  {
    vector<int> distance(n, -1) ;
    queue<int> discovered ;
    discovered.push(start) ;
    distance[start]=0 ;
    while(!discovered.empty())
      {
        t=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj[t].size() ; i++)
          {
            if(distance[adj[t][i]]==-1)
              {
                distance[adj[t][i]]=distance[t]+1 ;
                discovered.push(adj[t][i]) ;
              }
          }
      }
    return distance[end] ;
  }

bool check(string a, string b)
  {
    int c=0 ;
    if(a.length()!=b.length()) return false ;
    for(int i=0 ; i<a.length() ; i++)
        if(a[i]!=b[i]) c++ ;
    if(c==1) return true ;
    return false ;
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;


  while(T--)
  {
    n=1 ;
    map<string, int> cnc ;
    map<int, string> ncn ;
    dict.clear() ;
    adj.clear() ;
    while(1)
      {
        cin>> temp ;
        if(temp=="*") break ;
        dict.push_back(temp) ;
        cnc[temp]=n ;
        ncn[n]=temp ;
        n++ ;
      }
    adj.resize(n) ;
    for(int i=1 ; i<n ; i++)
      {
        for(int j=1 ; j<n ; j++)
          {
            if(j==i) continue ;
            if(check(ncn[i], ncn[j]))
                  adj[i].push_back(j) ;
          }
      }
    getline(cin, temp) ;
    while(1)
      {
        getline(cin, temp) ;
        stringstream ss;
        if(temp.length()==0) break ;
        ss.str(temp);
        string s, e ;
        getline(ss, s, ' ') ;
        getline(ss, e) ;
        cout<< s << " " << e << " " << bfs(cnc[s],cnc[e]) << endl ;
      }
    if(T!=0) cout<< endl ;
  }

   return 0 ;
 }
