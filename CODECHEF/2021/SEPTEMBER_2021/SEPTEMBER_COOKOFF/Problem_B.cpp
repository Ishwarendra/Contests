#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    char first = s[0];
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (first != s[i])
            cnt++, first = s[i];
    }

    // Handle impossible case
    if (cnt < k)
    {
        cout << -1 << endl;
        return;
    }

    // start 0
    if (s[0] == '0')
    {
        if (k & 1)
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
        else
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
    }
    // start 1
    else
    {
        if (k & 1)
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
        else
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    cout << i + 1 << "\n";
                    return;
                }
            }
        }
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
