#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

const ll mod = 998244353;
vector<ll> dp;

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<ll> mex(const vector<ll> &a)
{
    dp.resize(a.size());
    if (a[0])
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    
    ll expon = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            expon++;
        else if (a[i] == 1)
            expon++;
    }

    ll ans = binpow(2, expon) - 1;

    cout << ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    // cout << binpow(2, 5);
    return 0;
}