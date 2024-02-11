#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unordered_set<ll> primeFactors(ll n)
{
    unordered_set<ll> prime_n;
    if (n % 2 == 0)
    {
        prime_n.insert(2);
        while (n % 2 == 0)
        {
            n = n >> 1;
        }
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        if (n % i == 0)
        {
            prime_n.insert(i);
            while(n % i == 0)
                n = n / i;
        }
    }
    if (n > 2)
        prime_n.insert(n);

    return prime_n;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a == 1)
    {
        cout << "YES\n";
        return;
    }

    ll g = gcd(a, b);
    while(g != 1)
    {
        a /= g;
        g = gcd(a, b);
    }

    if (b % a == 0)
        cout << "YES\n";
    else    
        cout << "NO\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}