#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll n, m;
    cin >> n >> m;
    if (n == 1 and m == 1)
    {
        cout << "0\n";
    }
    else if (m == 1 or n == 1)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
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