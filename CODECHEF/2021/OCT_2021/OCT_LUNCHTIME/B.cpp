#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n, v;
    cin >> n >> v;
    ll cost2;
    if (v == 1)
    {
        cost2 = n * (n - 1) / 2LL;
        cout << cost2 << " " << cost2 << "\n";
    }

    else
    {
        ll term1 = (n - v) * (n - v + 1) / 2LL;
        ll cost1 = min(n - 1, v) + ((n - v) > 0 ? term1 - 1LL : 0LL);

        // ll term2 = (n - 2) * (n - 1) / 2LL;
        // cost2 = (n - 1) * v + (term2 > 0 ? term2 : 0LL);
        cost2 = n * (n - 1) / 2LL;
        if (n == 1)
            cout << "0 0\n";
        else
            cout << max(cost1, cost2) << " " << min(cost1, cost2) << "\n";
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