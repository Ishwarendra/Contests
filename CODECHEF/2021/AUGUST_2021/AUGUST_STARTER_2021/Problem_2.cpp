#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n, k;
    ll s;
    cin >> n >> k >> s;

    ll ans = (s - n*n)/(k - 1);
    cout << ans << "\n";

}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}