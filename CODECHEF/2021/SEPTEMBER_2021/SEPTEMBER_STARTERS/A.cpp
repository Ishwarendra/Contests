#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n, s;
    cin >> n >> s;

    ll x = (n * (n + 1) / 2) - s;

    if (x < 1 or x > n)
        x = -1;
    cout << x << endl;

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}