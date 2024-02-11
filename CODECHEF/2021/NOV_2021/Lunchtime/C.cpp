#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll n; cin >> n;
    ll ans = n;

    ll least_prime = -1;
    for(ll i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            least_prime = i;
            break;
        }
    }   
    if (least_prime == -1)
        least_prime = n;
    ans = ans / least_prime;
    ans *= (least_prime + 1);
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