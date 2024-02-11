#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

char num[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool all_nine(string s)
{
    for(char &ch : s)
        if (ch != '9')
            return false;
    
    return true;
}


ll digit_prod(string n)
{
    // if (n.length() == 0)
    //     return 0;

    ll prod = 1;
    for(char &ch : n)
        prod *= (ch - '0');

    return prod;
}

char next(char ch)
{
    int tmp = ch - '0';
    return num[tmp + 1];
}


void solve()
{
    string s; ll k;
    cin >> s >> k;
    sort(s.begin(), s.end());
    
    while(k--)
    {
        if (all_nine(s))
            break;
        s[0] = num[s[0] - '0' + 1];
        sort(s.begin(), s.end());
    }

    ll ans = digit_prod(s);
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