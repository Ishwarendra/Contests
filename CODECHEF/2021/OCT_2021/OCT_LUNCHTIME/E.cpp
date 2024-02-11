#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

// vector<unordered_map<ll, ll>> pfact;

// void primeFactors(int n)
// {
//     unordered_map<ll, ll> m;
//     while (n % 2 == 0)
//         m[2]++;
    
 
//     for (int i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             m[i]++;
//             n = n / i;
//         }
//     }
//     if (n > 2)
//         m[n]++;
    
//     pfact.push_back(m);
// }

ll gcd(ll a, ll b)
{
    if (b == 0LL)
        return a;
    return gcd(b, a % b);
     
}

ll gcd_array(vector<ll> &arr)
{
    ll g = 0LL;
    for(auto i : arr)
        g = gcd(g, i);
    return g;
}



void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    // vector<ll> copy(a);

    // for(auto i : copy)
    //     cout << i << " ";

    ll max_gcd = gcd_array(a);
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            ll tmp = a[i] * a[j];
            ll a_i = a[i];
            ll a_j = a[j];

            a[i] = tmp, a[j] = tmp;

            max_gcd = max(max_gcd, gcd_array(a));
            a[i] = a_i, a[j] = a_j;

        }
    }

    cout << max_gcd << "\n";

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}