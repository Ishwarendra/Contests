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
    
    int n;
    std::cin >> n;

    std::vector a(n, std::vector(n, 0));
    auto b = a;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> b[i][j];
    }

    auto rotate = [&](auto &b)
    {
        auto c = b;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                c[i][j] = b[n - 1 - j][i];
        }

        return c;
    };

    auto valid = [&](auto &a, auto &b)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1 and b[i][j] == 0)
                    return false;
            }
        }

        return true;
    };

    for (int i = 0; i < 12; i++)
    {
        if (valid(a, b))
        {
            std::cout << "Yes";
            return 0;
        }

        a = rotate(a);
    }

    std::cout << "No";

    return 0;
}