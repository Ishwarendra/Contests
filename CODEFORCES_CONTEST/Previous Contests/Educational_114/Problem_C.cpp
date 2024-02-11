#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;

    for(ll &x : a)
    {
        cin >> x;
        sum += x;
    }

    sort(a.begin(), a.end());
    int m; cin >> m;

    for(int i = 0; i < m; i++)
    {
        ll sum_copy1 = sum;
        ll sum_copy2 = sum;
        ll x, y;
        cin >> x >> y;

        ll ans = 0LL;
        ll ans2 = 0LL;
        
        int f1 = lower_bound(all(a), x) - a.begin();
        int f2 = upper_bound(all(a), x) - a.begin();

        if (f1 == a.size() or a[f1] > x)
            f1--;
        if (f2 == a.size())
            f2--;
        // cout << f1 << "\n";
        if (a[f1] > x)
        {
            sum_copy1 -= a[f1];
            ans += max(y - sum_copy1, 0LL);
        }

        else
        {
            sum_copy1 -= a[f1];
            ans += (x - a[f1]);
            ans += max(y - sum_copy1, 0LL);
        }
        if (a[f2] > x)
        {
            sum_copy2 -= a[f2];
            ans2 += max(y - sum_copy2, 0LL);
        }

        else
        {
            sum_copy2 -= a[f2];
            ans2 += (x - a[f2]);
            ans2 += max(y - sum_copy2, 0LL);
        }

        cout << min(ans, ans2) << "\n";
    }       

}

int main()
{
    int t = 1; 
    // cin >> t;
    while(t--)
        solve();
    return 0;
}