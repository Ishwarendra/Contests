#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    auto firstPrime = [&](i64 x)
    {
        for (i64 i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return i;
        }

        return -1LL;
    };

    auto p = firstPrime(n);
    n /= p;
    if (n % p == 0)
    {
        n /= p;
        std::cout << p << " " << n << "\n";
    }
    else
    {
        i64 left = 1, right = i64(sqrtl(n)) * 2;
        i64 q = -1;
        while (left <= right)
        {
            i64 mid = (left + right) >> 1LL;
            if (mid * mid >= n)
                q = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        std::cout << q << " " << p << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}