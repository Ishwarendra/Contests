#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define print(a) cout << a << "\n";
using vi = vector<int>;
using ll = long long;

int main()
{
    ll y, k, n;
    cin >> y >> k >> n;

    ll x = k - y%k;
    vector<ll> ans;
    
    bool no_ele = true;
    for(ll i = x; i <= n - y; i += k)
    {
        no_ele = false;
        cout << i << " ";
    }
    if (no_ele)
        cout << -1 << "\n";

    return 0;
}