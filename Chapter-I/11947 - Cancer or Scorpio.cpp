#include<iostream>
#include<string>

using namespace std;

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0)
        || y % 400 == 0;
}

int main()
{
    int n;
    while (cin >> n)
    for (int i = 1; i <= n; i++)
    {

        string s; cin >> s;
        string t;

        t = s.substr(0, 2);
        int m = stoi(t);
        t = s.substr(2, 2);
        int d = stoi(t);
        t = s.substr(4, 8);
        int y = stoi(t);


        int month[12] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };
        if (isLeap(y))
            month[1]++;


        d += 280;

        while (d > month[m - 1])
        {
            d -= month[m - 1];
            m++;

            if (m > 12)
            {
                if (isLeap(y) && !isLeap(y + 1))
                    month[1]--;
                else if (!isLeap(y) && isLeap(y + 1))
                    month[1]++;

                y++;
                m %= 12;
            }
        }


        printf("%d %02d/", i, m);
        printf("%02d/%02d ", d, y);
        if (m == 1)
        {
            if (d < 20)
                cout << "capricorn";
            else
                cout << "aquarius";
        }
        else if (m == 2)
        {
            if (d < 19)
                cout << "aquarius";
            else
                cout << "pisces";
        }
        else if (m == 3)
        {
            if (d < 21)
                cout << "pisces";
            else
                cout << "aries";
        }
        else if (m == 4)
        {
            if (d < 20)
                cout << "aries";
            else
                cout << "taurus";
        }
        else if (m == 5)
        {
            if (d < 21)
                cout << "taurus";
            else
                cout << "gemini";
        }
        else if (m == 6)
        {
            if (d < 22)
                cout << "gemini";
            else
                cout << "cancer";
        }
        else if (m == 7)
        {
            if (d < 23)
                cout << "cancer";
            else
                cout << "leo";
        }
        else if (m == 8)
        {
            if (d < 23)
                cout << "leo";
            else
                cout << "virgo";
        }
        else if (m == 9)
        {
            if (d < 23)
                cout << "virgo";
            else
                cout << "libra";
        }
        else if (m == 10)
        {
            if (d < 24)
                cout << "libra";
            else
                cout << "scorpio";
        }
        else if (m == 11)
        {
            if (d < 23)
                cout << "scorpio";
            else
                cout << "sagittarius";
        }
        else if (m == 12)
        {
            if (d < 22)
                cout << "sagittarius";
            else
                cout << "capricorn";
        }
        cout << endl;
    }
    return 0;
}
