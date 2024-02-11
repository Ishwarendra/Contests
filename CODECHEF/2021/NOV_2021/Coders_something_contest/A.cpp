#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

char num[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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

bool all_nine(string s)
{
    for(char &ch : s)
        if (ch != '9')
            return false;
    
    return true;
}

string best_move(string s)
{
    string revert = s;  
    int n = s.length();
    int max_prod = 0;
    string best;
    for(int i = 0; i < n; i++)
    {
        if (s[i] == '9')
            continue;

        s[i] = next(s[i]);
        int cur = digit_prod(s);
        if (cur >= max_prod)
        {
            max_prod = cur;
            best = s;
        }
        s = revert;
    }

    return best;
}

void solve()
{
    string n; int k;
    cin >> n >> k;  
    ll ans;
    // map<int, int> m;
    while(k--)
    {
        if (all_nine(n))
            break;
        n = best_move(n);
        // cout << n << " ";
    }  

    ans = digit_prod(n);
    cout << ans << "\n";
}

int main()
{
    // FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    // string s = "2221";
    // cout << best_move(s);
    return 0;
}