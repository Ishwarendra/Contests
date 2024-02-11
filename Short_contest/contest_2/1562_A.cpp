#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll range = r - l + 1;
    ll rem = 0;
    if (r - 2*l < 0)
    {
        rem = range - 1;
    }
    else
    {
        rem = min(range, (r - 1)/2);
    }

    cout << rem << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}