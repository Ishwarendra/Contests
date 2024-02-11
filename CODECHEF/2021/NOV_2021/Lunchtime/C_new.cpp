#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}


void solve()
{
    ll n; cin >> n;
    
    ll left = n, right = n*n;
    ll best = 1e18, cur_best = 1e18;
    while(left <= right)
    {
        ll mid = left - (right - left)/2;
        
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