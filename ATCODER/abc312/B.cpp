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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto check = [&](int px, int py)
    {
        auto good = [&](int x, int y, int add)
        {
            for (int i = x; i < x + 3; i++)
            {
                for (int j = y; j < y + 3; j++)
                {
                    if (a[i][j] != '#')
                        return false;
                }
            }

            for (int i = x; i < x + 3; i++)
            {
                if (a[i][y + add] != '.')
                    return false;
            }

            for (int j = y; j < y + 3; j++)
            {
                if (a[x + add][j] != '.')
                    return false;
            }

            if (a[x + add][y + add] != '.')
                return false;

            return true;
        };

        if (!good(px, py, 3) or !good(px + 6, py + 6, -1))
            return false;

        return true;
    };

    for (int i = 0; i + 8 < n; i++)
    {
        for (int j = 0; j + 8 < m; j++)
        {
            if (check(i, j))
                std::cout << i + 1 << " " << j + 1 << "\n";
        }
    }

    return 0;
}