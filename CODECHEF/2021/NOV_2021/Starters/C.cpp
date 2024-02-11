#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool cmp(const string &a, const string &b)
{
    int zero1 = 0, zero2 = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if (a[i] == '0')
            zero1++;
        if (b[i] == '0')
            zero2++;
    }
    
    return (zero1 > zero2);
}


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> stru(n);
    for(int i = 0; i < n; i++)
        cin >> stru[i];
    
    sort(stru.begin(), stru.end(), cmp);
    string s;
    for(string i : stru)
        s += i; 

    vector<ll> dp(n*m + 1);
    ll ans = 0LL;
    // cout << s << "\n";
    dp[n*m - 1] = (s[n*m - 1] == '1' ? 0 : 1);

    for(int i = n*m - 2; i >= 0; i--)
    {
        if (s[i] == '1')
            dp[i] = dp[i + 1];
        else
            dp[i] = 1 + dp[i + 1];
    }

    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            ans += dp[i + 1];
    }

    cout << ans << "\n";

}

int32_t main()
{
    // FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}