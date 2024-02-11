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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    auto vertical = [&](auto &x, int times = 1)
    {
        auto c = x;
        for (int i = 0; i < n; i++)
            c[(i + times) % n] = x[i];
        return c;
    };

    auto horizontal = [&](auto &x, int times = 1)
    {
        auto c = x;
        for (int i = 0; i < n; i++)  
        {
            for (int j = 0; j < m; j++)
                c[i][(j + times) % m] = x[i][j];
        }
        return c;
    };

    auto check = [&](int s, int t)
    {
        auto c = vertical(a, s);
        c = horizontal(c, t);
        return c == b;
    };

    for (int i = 0; i < 61; i++)
    {
        for (int j = 0; j < 61; j++)
        {
            if (check(i, j))
            {
                std::cout << "Yes\n";
                return 0;
            }
        }
    }
    
    std::cout << "No\n";

    return 0;
}