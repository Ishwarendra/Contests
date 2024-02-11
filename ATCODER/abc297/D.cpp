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
    
    i64 a, b;
    std::cin >> a >> b;

    i64 ans = 0;
    if (a < b)
        std::swap(a, b);

    std::function<i64(i64, i64)> gcd = [&](i64 a, i64 b)
    {
        if (b == 0 or a == b)
            return a;

        i64 k = (a - 1) / b;
        ans += k;
        a -= k * b;
        return gcd(b, a);
    };

    gcd(a, b);
    std::cout << ans;
    
    return 0;
}