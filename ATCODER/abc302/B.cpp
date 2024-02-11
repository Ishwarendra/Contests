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

    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < m;
    };

    const std::string t = "snuke";
    auto get = [&](int x, int y, std::array<int, 2> dir)
    {
        auto [dx, dy] = dir;
        for (int i = 0; i < 5; i++)
        {
            if (!safe(x, y) || a[x][y] != t[i])
                return false;
            x += dx, y += dy;
        }
        return true;
    };

    std::vector<std::array<int, 2>> dirs {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (auto dir : dirs)
            {
                if (get(i, j, dir))
                {
                    auto [dx, dy] = dir;
                    int x = i + 1, y = j + 1;
                    for (int p = 0; p < 5; p++)
                    {
                        std::cout << x << " " << y << "\n";
                        x += dx, y += dy;
                    }
                    
                    return 0;
                }
            }
        }
    }

    return 0;
}