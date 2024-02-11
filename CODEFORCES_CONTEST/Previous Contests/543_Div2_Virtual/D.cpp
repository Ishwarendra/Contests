#include <bits/stdc++.h>

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
    
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;

    if (a < b)
        std::swap(a, b);

    i64 max = -1, min = 1e18;

    auto f = [&](i64 x)
    {
        return 1LL * n * k / std::gcd<i64>(1LL * n * k, x);
    };

    for (int i = 0; i < n; ++i)
    {
        i64 back = 1LL * i * k + a - b;
        i64 front = 1LL * i * k + a + b;

        max = std::max(max, f(back));
        max = std::max(max, f(front));
        min = std::min(min, f(back));
        min = std::min(min, f(front));
    }

    std::cout << min << " " << max;
    
    return 0;
}