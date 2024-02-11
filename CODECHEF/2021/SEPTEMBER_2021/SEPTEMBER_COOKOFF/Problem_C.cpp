#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    bool same = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            same = false;
            break;
        }
    }

    if (same)
    {
        cout << "YES" << endl;
        return;
    }

    ll zero = 0, one = 0;
    for (auto x : t)
    {
        if (x == '1')
        {
            one++;
        }
        else
        {
            zero++;
        }
    }

    if (one > 0 and zero > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}