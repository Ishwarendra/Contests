#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(x...) 1;
#endif

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    set<ll> s;
    vector<ll> suffix(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], v[i].second);
    }
    ll ans = 1e9;

    for (int i = 0; i < n; i++)
    {
        ll maxi = 1e9;
        ll maxEle = suffix[i + 1];
        if (i + 1 < n)
        {
            maxi = abs(v[i].first - suffix[i + 1]);
        }
        ll mini = 1e9;
        if (s.size() > 0)
        {
            auto iterator = s.lower_bound(v[i].first);

            if (iterator != s.end() && *iterator >= maxEle)
            {
                mini = min(mini, abs(v[i].first - *iterator));
            }
            if (iterator != s.begin() && *(--iterator) >= maxEle)
            {
                mini = min(mini, abs(v[i].first - *iterator));
            }
        }
        ans = min(ans, min(mini, maxi));
        s.insert(v[i].second);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}