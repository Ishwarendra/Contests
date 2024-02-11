#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    int old_k = k;

    i64 c = 1LL * n * m;
    c *= 2;
    if (c % k)
    {
        std::cout << "NO\n";
        return 0;
    }

    if (k % 2 == 0) 
        k /= 2;

    int gcd = std::gcd(k, m);
    k /= gcd;
    int second = m / gcd;

    gcd = std::gcd(k, n);
    int third = n / gcd;

    if (second < m and old_k % 2)
        second *= 2;
    else if (old_k % 2)
        third *= 2;

    std::cout << "YES\n";
    std::cout << "0 0\n";
    std::cout << "0 " << second << "\n";
    std::cout << third << " 0\n";
    
    return 0;
}