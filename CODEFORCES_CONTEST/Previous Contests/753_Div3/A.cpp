#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

map<char, int> m;
void make_map(string a)
{
    for(int i = 0; i < 26; i++)
        m[a[i]] = i + 1;
}

void solve()
{
    string arrange; cin >> arrange;
    make_map(arrange);
    string s; cin >> s;
    int n = s.length();
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        ans += abs(m[s[i]] - m[s[i - 1]]);
    }

    cout << ans << "\n";
    m.clear();
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}