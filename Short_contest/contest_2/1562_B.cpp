#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;


vector<bool> seive(ll n)
{
        vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

void solve()
{
    vector<bool> prime = seive(100);
    int k; cin >> k;
    string n;
    cin >> n;

    for(int i = 0; i < n.length(); i++)
    {
        // cout << n[i] << "\n";
        if (n[i] - '0' == 1 or n[i] - '0' == 4 or n[i]  - '0'== 6 or n[i] - '0' == 8 or n[i] - '0' == 9)
        {
            cout << 1 << "\n" << n[i] << "\n";
            return;
        }
    }
    // only odd-digits
    for(int i = 0; i < k; i++)
    {
        int tens = n[i] - '0';
        for(int j = i + 1; j < k; j++)
        {
            int unit = n[j] - '0';
            if (!prime[tens*10 + unit])
            {
                cout << 2 << "\n" << tens*10 + unit << "\n";
                return;
            }
        }
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}