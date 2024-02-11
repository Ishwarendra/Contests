#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    
    vector<ll> arr {a, b, c};
    sort(arr.begin(), arr.end());

    if (a + b + c - 3 < m)
    {
        cout << "NO\n";
        return;
    }

    else
    {
        ll coverable_range = arr[2] - arr[1] - arr[0] - 1;
        if (m >= coverable_range)
            cout << "YES\n";
        
        else
            cout << "NO\n";
    }
    
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    // vi a{2, 3, 3, 6};
    // cout << upper_bound(a.begin(), a.end(), 4) - a.begin();
    return 0;
}