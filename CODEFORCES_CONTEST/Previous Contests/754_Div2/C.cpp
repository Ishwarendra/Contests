#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool armano(string s)
{
    if (s.length() < 2)
        return false;
    for(int i = 1; i < s.length(); i++)
    {
        if (s[i] == 'a' and s[i - 1] == 'a')
            return true;
    }
    return false;
}

bool a_with_gap1(string s)
{
    if (s.length() < 3)
        return false;
    for(int i = 0; i < s.length() - 2; i++)
    {
        if (s[i] == 'a' and s[i + 2] == 'a')
            return true;
    }
    return false;
}

bool a_with_gap2(string s)
{
    if (s.length() < 4)
        return false;   
    for(int i = 0; i < s.length() - 3; i++)
    {
        if (s[i] == 'a' and s[i + 3] == 'a' and (s[i + 1] != s[i + 2]))
            return true;
    }
    return false;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    if (armano(s))
    {
        cout << "2\n";
    }
    else if (a_with_gap1(s)) 
    {
        cout << "3\n";
    }
    else if (a_with_gap2(s))
        cout << "4\n";
    else
        cout << "-1\n";
}

int main()
{
    // FIO   
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    // string a = "a";
    // cout << armano(a) << " " << a_with_gap(a);
    
    return 0;
}