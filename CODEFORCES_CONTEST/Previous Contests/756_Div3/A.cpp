#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool only_odd(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if ((s[i] - '0') % 2 == 0)
            return false;
    }
    return true;
}

void solve()
{
    string s; cin >> s;
    if ((s.back() - '0') % 2 == 0)
        cout << "0\n";
    else if ((s[0] - '0') % 2 == 0)
        cout << "1\n";
    else if (only_odd(s))
        cout << "-1\n";
    else
        cout << "2\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}