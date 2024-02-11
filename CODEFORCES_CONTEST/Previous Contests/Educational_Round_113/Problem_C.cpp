#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;
const long long mod = 998244353;
vector<long long> fct(200010, 1);


void make_factorial(vi &fct)
{
    for(int i = 1; i < fct.size(); i++)
        fct[i] = i * fct[i - 1] % mod;
}

ll P(ll n, ll r)
{
    return (fct[n]/fct[r]) % mod;
}

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);

    ll mx1 = 0, mx2 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > mx1)
            mx2 = mx1, mx1 = a[i];
        else if (a[i] > mx2)
            mx2 = a[i];
    }

    if (mx1 == mx2)
    {
        cout << fct[n] << "\n";
        return;
    }
    else if (mx1 - mx2 > 1)
    {
        cout << 0 << "\n";
        return;
    }
    else
    {
        int x = 0;
        for(int i = 0; i < n; i++)
            if (a[i] == mx2) x++;
        
        ll ans = ( ((x * fct[x]) % mod) * ((P(n, x + 1)) % mod) )% mod;
        cout << ans << "\n";
        return;
    }


}

int main()
{
    make_factorial(fct);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}