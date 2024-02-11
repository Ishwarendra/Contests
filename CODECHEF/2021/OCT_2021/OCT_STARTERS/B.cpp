#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int smallest_factor(int n)
{
    for(int i = 3; i*i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}

void solve()
{
    int n; int a, b;
    cin >> n >> a >> b; // a-> even, b -> odd

    int ans = 0;

    // both even odd negative (including 0)
    if (a <= 0 and b <= 0)
    {
        if (n & 1)
            ans += b;
        else
            ans += a;
    }

    // even positive odd negative
    if (a >= 0 and b < 0)
    {
        while (n % 4 == 0)    
            ans += a, n >>= 1;
        
        if (n % 2 == 0)
            ans += a;
        else
            ans += b;
    }

    // even negative odd positive
    if (a < 0 and b >= 0)
    {
        if (n % 2 == 0)
        {
            ans += a;
            while(n % 2 == 0)
                n >>= 1;
        }

        while(n != 1)
        {
            int factor = smallest_factor(n);
            while(n % factor == 0 and n != 1)
                ans += b, n /= factor;
        }
    }

    // both positive
    if (a > 0 and b > 0)
    {
        while (n % 2 == 0)    
            ans += a, n >>= 1;

        while (n != 1)
        {
            int factor = smallest_factor(n);
            while((n % factor == 0) and n != 1)
                ans += b, n /= factor;
        }
    }

    cout << ans << "\n";

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    // cout << smallest_factor(45)
    ;return 0;
}