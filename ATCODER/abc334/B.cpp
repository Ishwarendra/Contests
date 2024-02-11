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
    
    i64 a, m, L, R;
    std::cin >> a >> m >> L >> R;

    auto sub = [&](auto x, auto y)
    {
        x = (x - y) % m;
        if (x < 0)
            x += m;
        return x;
    };

    i64 min = L + sub(a, L);
    i64 max = R - sub(R, a);

    std::cout << (max - min) / m + 1;

    return 0;
}