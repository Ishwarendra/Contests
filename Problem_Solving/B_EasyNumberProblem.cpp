#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

const long long mod = 1073741824;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    // Calculate divisors for 100^3 numbers (seive)
    vector<ll> divisors(a*b*c + 1);
    for(int i = 1; i <= a*b*c; i++)
    {
        for(int j = i; j <= a*b*c; j += i)
            divisors[j] = (divisors[j] + 1) % mod;
    }

    ull sum = 0;
    for(int i = 1; i <=a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            for(int k = 1; k <= c; k++)
                sum = (sum + divisors[i*j*k]) % mod;
        }
    }

    cout << sum << "\n";

}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}