#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll a, b, x, y, n;
    cin >> a >> b >> x >>y >> n ;
    ll ans = INT64_MAX;

    int cnt = 2;
    while(cnt--)
    {
        ll new_a = min(n, a - x);
        ll new_b = min(n - new_a, b - y);

        ans = min(ans, (a - new_a)*(b - new_b));

        swap(x, y), swap(a, b); // decrease b first now
    }

    cout << ans << "\n";

}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}