#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string flipped;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            flipped += '0';
        else
            flipped += '1';
    }

    int res = 0;
    bool flip = false;
    for (int i = 0; i < n; i++)
    {
        if (!flip)
        {
            if (s[i] == '0')
                res++, flip = !flip;
        }
        else
        {
            if (flipped[i] == '0')
                res++, flip = !flip;
        }

    }

    cout << res << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}