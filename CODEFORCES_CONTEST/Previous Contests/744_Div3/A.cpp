#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    map<char, int> m;
    for(int i = 0;  i < s.length(); i++)
    {
        m[s[i]]++;
    }

    if (m['B'] == m['C'] + m['A'])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
          solve();
    return 0;
}