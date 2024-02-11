#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool f(string s, char ch)
{
    // char ch = '1';
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] != ch)
            return false;
    }
    return true;
}

bool consec_zeroes(string s)
{
    int n = s.length();
    int cnt;
    (s[0] == '0') ? cnt = 1 : cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if (s[i] == '0' and s[i - 1] == '1')
            cnt++;
    }
    return (cnt > 1);
}

void solve()
{
    string s; cin >> s;
    if (f(s, '1'))
    {
        cout << 0 << endl;
        return;
    }
    if (f(s, '0'))
    {
        cout << 1 << endl;
        return;
    }

    if (consec_zeroes(s))
    {
        cout << 2 << endl;
        return;
    }

    else
    {
        cout << 1 << endl;
        return;
    }


}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}