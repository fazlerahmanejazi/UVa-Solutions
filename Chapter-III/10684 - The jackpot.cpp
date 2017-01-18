#include<bits/stdc++.h>
using namespace std;

int main()
{
 ios_base::sync_with_stdio (false);
    int n;
    while(cin >> n && n != 0)
    {
        int sum = 0, temp, max = -10000;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            sum += temp;
            if(sum > max) max = sum;
            if(sum < 0) sum = 0;
        }
        (max > 0) ? cout << "The maximum winning streak is " << max << "." << endl : cout << "Losing streak." << endl ;
    }
    return 0 ;
}
