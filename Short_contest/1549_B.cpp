#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n;
    string tmp1, tmp2;

    cin >> n >> tmp1 >> tmp2;

    tmp1 = "2" + tmp1 + "2", tmp2 = "2" + tmp2 + "2";

    vector<string> a(n + 2), b(n +2);

    for(int i = 0; i < n + 2; i++)
        b[i] = tmp1[i], a[i] = tmp2[i];

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if (a[i] == "1" and b[i - 1] == "1")
            ans++, b[i - 1] = "2";
        else if (a[i] == "1" and b[i] == "0")
            ans++, b[i] = "2";
        else if (a[i] == "1" and b[i + 1] == "1")
            ans++, b[i + 1] = "2";
    }

    cout << ans << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}