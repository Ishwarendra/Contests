#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;


void solve()
{
    ll n; 
    vi a(n), b(n - 1);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n-1; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll x;
    if (b[0] - a[1] == b[b.size() - 1] - a[a.size() - 1])
        x = b[0] - a[1];

    for(int pos = 1; pos < n - 1; pos++)
    {
        ll cur_x = -1;

        if (b[0] - a[0] == b[b.size() - 1] - a[a.size() - 1])
        {
            cur_x = b[0] - a[0];
        }
        x = min(x, cur_x);
    }

    cout << x << "\n";
}

int main()
{
    FIO
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}