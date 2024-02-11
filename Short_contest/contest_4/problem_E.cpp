#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    string s;
    bool turn = (a > b);
    if (b == 0)
    {
        if (a == 0)
        {
            for (int i = 0; i <= c; i++)
                s += "1";
        }
        else
        {
            for (int i = 0; i <= a; i++)
                s += "0";
        }
        cout << s << endl;
        s.clear();
        return;
    }

    for (int i = 0; i < b; i++)
        s += to_string(i % 2);
    if (b & 1)
    {
        for (int i = 0; i < a; i++)
            s += "0";
        for (int i = 0; i <= c; i++)
            s += "1";
    }
    else
    {
        for (int i = 0; i < c; i++)
            s += "1";
        for (int i = 0; i <= a; i++)
            s += "0";
    }

    cout << s << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}