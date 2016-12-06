#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int n, m, s, e, r;
bool conflict;
bool t[1000100];

bool check() {
	for(int i = s; i < e; i++) {
		if(t[i]) return false;
		t[i] = true;
	}
	return true;
}

int main()
{
	while(1)
	{
		cin>>n >> m ;
		if(n == 0 && m == 0) break;
		conflict = false;

		memset(t, false, sizeof t);
		for(int i = 0; i < n; i++)
		{
			cin>> s>> e ;
			if(!conflict && !check()) conflict = true;
		}
		for(int i = 0; i < m; i++)
		{
			cin>> s >> e >> r;
			while(!conflict && s < 1000000)
		  {
				if(!check()) conflict = true;
				s += r;
				e = min(e + r, 1000000);
			}
		}
		if(!conflict) cout<< "NO CONFLICT" << endl ;
		else cout<< "CONFLICT" < endl ;
	}
}
