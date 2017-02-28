#include <bits/stdc++.h>
using namespace std ;

int N, c, temp, prof, guy ;
char age, dir, a, b ;
vector<vector<int> > adj_m ;
vector<vector<int> > adj_y ;
vector<vector<int> > energy(27, vector<int>(27)) ;
vector<vector<int> > value ;

void bfs_y()
  {
    queue<int> discovered ;
    discovered.push(guy) ;
    value[0][guy]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj_y[temp].size() ; i++)
          {
            if(value[0][adj_y[temp][i]]==-1)
              {
                value[0][adj_y[temp][i]]=value[0][temp]+energy[temp][adj_y[temp][i]] ;
                discovered.push(adj_y[temp][i]) ;
              }
          }
      }
  }

void bfs_m()
  {
    queue<int> discovered ;
    discovered.push(prof) ;
    value[1][prof]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj_m[temp].size() ; i++)
          {
            if(value[1][adj_m[temp][i]]==-1)
              {
                value[1][adj_m[temp][i]]=value[1][temp]+energy[temp][adj_m[temp][i]] ;
                discovered.push(adj_m[temp][i]) ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  while(cin>>N)
    {
      if(N==0) break ;
      c=0 ;
      vector<bool> avail(26, true) ;
      map<char, int> cnc ;
      map<int, char> ncn ;
      adj_m.clear() ;
      adj_y.clear() ;
      adj_m.resize(27) ;
      adj_y.resize(27) ;
      value.clear() ;
      vector<int> dump(27, -1) ;
      value.push_back(dump) ; value.push_back(dump) ;
      for(int i=0 ; i<N ; i++)
        {
          cin>> age >> dir >> a >> b >> temp ;
          if(avail[a-65]) {avail[a-65]=false ; c++ ; cnc[a]=c ; ncn[c]=a ; }
          if(avail[b-65]) {avail[b-65]=false ; c++ ; cnc[b]=c ; ncn[c]=b ; }
          if(age=='Y')
            {
              adj_y[cnc[a]].push_back(cnc[b]) ;
              energy[cnc[a]][cnc[b]]=temp ;
              if(dir=='B')
                {
                  adj_y[cnc[b]].push_back(cnc[a]) ;
                  energy[cnc[b]][cnc[a]]=temp ;
                }
            }
          else
            {
              adj_m[cnc[a]].push_back(cnc[b]) ;
              energy[cnc[a]][cnc[b]]=temp ;
              if(dir=='B')
                {
                  adj_m[cnc[b]].push_back(cnc[a]) ;
                  energy[cnc[b]][cnc[a]]=temp ;
                }
            }
        }
      cin>> a >> b ;
      if(avail[a-65]) {avail[a-65]=false ; c++ ; cnc[a]=c ; ncn[c]=a ; }
      if(avail[b-65]) {avail[b-65]=false ; c++ ; cnc[b]=c ; ncn[c]=b ; }
      guy=cnc[a] ;
      prof=cnc[b] ;
      bfs_y() ;
      bfs_m() ;
      vector<pair<int, char> > ans ;
      pair<int, char> pb ;
      for(int i=1 ; i<=c ; i++)
      {
        if(value[0][i]>=0 && value[1][i]>=0)
          {
            pb=make_pair(value[0][i]+value[1][i], ncn[i]) ;
            ans.push_back(pb) ;
          }
      }
      if(!ans.size()) { cout<< "You will never meet." << endl ; continue ; }
      sort(ans.begin(), ans.end()) ;
      c=ans.size() ;
      temp=ans[0].first ;
      cout<< ans[0].first  ;
      for(int i=0 ; i<ans.size() ; i++)
        if(temp==ans[i].first) cout<< " " << ans[i].second ;
        else break ;
      cout<< endl ;
    }
  return 0 ;
}
