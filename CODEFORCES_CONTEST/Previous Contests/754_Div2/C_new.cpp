#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool two(string s)
{
    for(int i = 1; i < s.length(); i++)
    {
        if (s[i] == 'a' and s[i - 1] == 'a')
            return true;
    }
    return false;
}

bool three(string s)
{
    for(int i = 2; i < s.length(); i++)
    {
        if (s[i] == 'a' and s[i - 2] == 'a')
            return true;
    }
    return false;
}

bool four(string s)
{
    for(int i = 3; i < s.length(); i++)
    {
        if (s[i] == 'a' and s[i - 3] == 'a' and (s[i - 1] != s[i - 2]))
            return true;
    }
    return false;
}

bool seven(string s)
{
    for(int i = 6; i < s.length(); i++)
    {
        if (s[i] == 'a' and s[i - 3] == 'a' and s[i - 6] == 'a' and (s[i - 5] == s[i - 4]) and (s[i - 2] == s[i - 1]) and (s[i - 1] != s[i - 4]))
            return true;
    }
    return false;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    if (two(s))
        cout << "2\n";
    else if (three(s))
        cout << "3\n";
    else if (four(s))
        cout << "4\n";
    else if (seven(s))
        cout << "7\n";
    else
        cout << "-1\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}