#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long
using vi = vector<int>;
using ld = long double;
using ull = unsigned long long;

const int mod = 998244353;

int gcdExtended(int a, int b, int* x, int* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

int modInverse(int a, int m = mod)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
         
        // m is added to handle negative x
        int res = (x % m + m) % m;
        return res;
    }
}


void solve()
{
    int n; cin >> n;
    ld num = n * (n + 1) * (n + 1);
    ld den = 4;

    if (num / den == (int)num/(int)den)
        cout << (int)num/(int)den << "\n";
    else 
    {
        int modinv = modInverse(4);
        int ans = (int)num * modinv;
        ans = ans % mod;
        cout << ans << "\n";
    }

}

int32_t main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}