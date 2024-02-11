#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    string ans = "";
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'L')
            ans += 'L';
        else if (s[i] == 'R')
            ans += 'R';
        else if (s[i] == 'U')
            ans += 'D';
        else if (s[i] == 'D')
            ans += 'U';
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