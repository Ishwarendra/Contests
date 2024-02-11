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

    i64 c = 2LL * n * m;
    if (c % k)
    {
        std::cout << "NO\n";
        return 0;
    }

    c /= k;

    std::cout << "YES\n";
    for (int i = 1; i * i <= c; i++) 
    {
        if (c % i == 0)
        {
            std::array<i64, 2> values{i, c / i};
            if (values[0] <= m and values[1] <= n)
                std::swap(values[0], values[1]);

            if (values[0] <= n and values[1] <= m)
            {
                std::cout << "0 0\n";
                std::cout << values[0] << " 0\n";
                std::cout << "0 " << values[1] << "\n";
                return 0;
            }
        }
    }

    return 0;
}