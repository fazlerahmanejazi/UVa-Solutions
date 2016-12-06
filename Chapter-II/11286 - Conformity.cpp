#include <bits/stdc++.h>
using namespace std ;
int main()
{
    map<vector<int>, int> Count;
    int n;
    vector<int> v(5);
    while (scanf("%d", &n) && n) {
        Count.clear();
        while (n--) {
            for(int i=0 ; i< 5; i++) scanf("%d", &v[i]);
            sort(v.begin(),v.end());
            Count[v]++;
        }
        map<vector<int>, int>::iterator it = Count.begin();
        int res = 0, Max = 0;
        while (it != Count.end()) {
            if (it->second == Max) res += it->second;
            else if (it->second > Max) {
                Max = it->second;
                res = it->second;
            }
            it++;
        }
        printf("%d\n", res);
    }
}
