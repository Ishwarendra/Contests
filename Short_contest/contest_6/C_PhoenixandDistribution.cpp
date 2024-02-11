#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    string ans;
    bool found = false;

    for (int i = 0; i < (n/k); i++)
    {
        ans += s[(i + 1) * k - 1];
        if (s[i * k] != s[(i + 1) * k - 1])
        {
            found = true;
            break;
        }
    }

    if (not found && n % k != 0)
        ans += s[n - 1];
    
    string alt;
    for(int i = k - 1; i < n; i++)
        alt += s[i];
    
    if (alt < ans) 
        ans = alt;
    cout << ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}