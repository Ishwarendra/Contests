#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;

    int ans = INT_MAX;
    // cout << "he";
    int steps = 0;
    for(int i = s.length() - 1; i >= 0; i--, steps++)
    {
        // cout << "here";
        char cur = s[i];
        char t1, t2;


        if (cur == '5')
            t1 = '2', t2 = '7';
        else if (cur == '0')
            t1 = '5', t2 = '0';
        else
            continue;

        for(int j = i - 1; j >= 0; j--)
        {
            // cout << steps << "\n";
            if (s[j] == t1 or s[j] == t2)
                ans = min(ans, i - j - 1 + steps);
        }

    }
    
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