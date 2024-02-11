#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

ll max_gap(vector<ll> &a)
{
    ll gap = -1;
    for(int i = 1; i < a.size(); i++)
    {
        gap = max(gap, a[i] - a[i - 1]);
    }

    return gap;
}

bool good(ll mid, vector<ll> &a, ll h)
{
    int n = a.size();
    ll dep_health = 0;
    for(int i = 1; i < n; i++)
    {
        dep_health += min(mid, a[i] - a[i - 1]);
    }
    dep_health += mid;

    return (dep_health >= h);
}

void solve()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);

    for(ll &x : a) cin >> x;

    ll left = 1, right = h;
    ll ans = h;
    while(left <= right)
    {
        ll mid = left + (right - left)/2;
        if (good(mid, a, h)) // check for smaller val it's ok
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}