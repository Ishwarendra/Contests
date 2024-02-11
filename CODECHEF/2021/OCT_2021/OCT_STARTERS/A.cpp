#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cur = s[i] - '0'; 
        for(int j = i + 1; (j - i <= 9 and j < n); j++)
        {
            if (abs(cur - (s[j] - '0')) == j - i)
                ans++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}