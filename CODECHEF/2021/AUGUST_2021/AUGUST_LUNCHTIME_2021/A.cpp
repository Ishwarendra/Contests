#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
#define debug(a) cout << a << "\n";

ll maxV(vector<ll> &v)
{
    ll n = v.size(), max = 0;
    for(ll i = 1; i < n; i++)
    {
        if (v[i] > v[max])
            max = i;
    }

    return v[max];
}

set<ll> get_ids(vector<ll> &v, ll max_val)
{
    set<ll> ids;
    for(ll i = 0; i < v.size(); i++)
    {
        if (v[i] == max_val)
            ids.insert(i);
    }

    return ids;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);


    for(ll i = 0; i < n; i++)
        cin >> a[i];

    set<ll> maxi = get_ids(a, maxV(a));

    ll ans = 0;
    for(auto &i : maxi)
    {
        (i - k + 1 < 0) ? ans += 0 : ans += (n - i);
    }

    cout << ans << "\n";
}

int main()
{       
    ll t; cin >> t;
    while(t--)
        solve();
    return 0;
}