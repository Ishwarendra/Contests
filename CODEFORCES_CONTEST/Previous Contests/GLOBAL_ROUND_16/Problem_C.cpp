#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    ll ans = 0;
    int pos = 0;
    for(int i = 0; i < n; i = pos)
    {
        if (pos < n - 1 and s1[pos] == '0' and s2[pos] == '0' and s1[pos + 1] == '1' and s2[pos + 1] == '1')
            ans += 2, pos += 2;
        
        else if (pos < n and s1[pos] == '0' and s2[pos] == '0')
            ans++, pos++;
        
        else if (s1[pos] != s2[pos])
            ans += 2, pos++;
        
        else
        {
            while(pos < n and s1[pos] == '1' and s2[pos] == '1')
                pos++;
            if (pos < n and (s1[pos] == '0' or s2[pos] == '0'))
                ans += 2, pos++;
        }
    }

    cout << ans << endl;

}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}