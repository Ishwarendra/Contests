#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n, s;
    cin >> n >> s;
    if (n == 1)
    {
        cout << s << "\n";
        return;
    }
    ll med_pos = (n + 1)/2 - 1;
    // s -= 1*(med_pos);   

    ll ans = s/(n - med_pos);
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