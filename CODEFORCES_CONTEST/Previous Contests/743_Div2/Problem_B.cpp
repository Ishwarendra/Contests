#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vi a(n), b(n);
    unordered_map<ll, ll> m;
    for(int i = 0; i < n; i++) cin >> a[i], m[a[i]] = i;   
    for(int i = 0; i < n; i++) cin >> b[i], m[b[i]] = i;      

    ll op = LONG_LONG_MAX;
    for(int i = 0; i < n; i++)
    {
        op = min(op, m[a[i] + 1] + i);
    }

    for(int i = 0; i < n; i++)
    {
        op = min(op, m[b[i] - 1] + i);
    }

    cout << op << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}