#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> x(n), p(m);
    
    cin >> x[0];
    ll start = x[0];

    for(int i = 1; i < n; i++)
    {
        cin >> x[i];
        x[i] -= x[i - 1];
    }

    for(ll &i : p) cin >> i;

    ll common_gap = (x[1]); // initial val

    for(int i = 2; i < n; i++)
        common_gap = __gcd(common_gap, x[i]);
    
    for(int i = 1; i <= m; i++)
    {
        if (common_gap % p[i - 1] == 0)
        {
            cout << "YES\n" << start << " " << i << "\n";
            return;
        }
    }

    cout << "NO\n";



}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}