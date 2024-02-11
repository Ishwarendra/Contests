#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int pos = 0;
    bool found = true;

    vector<bool> flag(n, false);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
            pos++;
        if (i % 2 == 1 and 2 * pos - 1 == i)
            flag[i] = true;
    }
    // reverse
    pos = 0; // reset
    for (int i = 0; i < n; i++)
    {
        flag[i] = false;
        if (a[i] == '0')
        {
            pos++;
        }
        if ((i % 2 != 0) && (i + 1 == 2 * pos))
        {
            flag[i] = true;
        }
    }
    pos = 0;
    for (int i = n - 1; i >= 0 && found; i--)
    {
        if (pos % 2 == 0)
        {
            if (a[i] != b[i])
            {
                if (flag[i])
                    pos++;
                else
                    found = false;
            }
        }
        else
        {
            if (a[i] == b[i])
            {
                if (flag[i])
                    pos++;
                else
                    found = false;
            }
        }
    }

    if (!found)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}