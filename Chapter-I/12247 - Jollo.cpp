#include <bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> a(3), b(2);
    vector<bool> available;

    int c;

    while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[0])
    {
        available.clear();
        available.resize(53, true);

        for (int i = 0; i < 3; ++i)
        {
            available[a[i]] = false;

            if (i < 2)
                available[b[i]] = false;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        c = 53;


        if (b[0] > a[2])
        {
            for (int i = 1; i <= 52 && i < c ; ++i)
                if (available[i])
                    c = i;
        }


        if (b[1] > a[2])
        {

            for (int i = a[2] + 1; i <= 52 && i < c ; ++i)
            {

                if (available[i])
                    c  = i;
            }
        }


        if (b[0] > a[1])
        {
             for (int i = a[1] + 1; i <= 52 && i < c ; ++i)
                if (available[i])
                    c  = i;
        }

        if (c  == 53)
            ca  = -1;

        cout << c << '\n';
    }

}
