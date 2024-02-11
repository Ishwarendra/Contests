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
    
    constexpr int n = 9;
    std::vector<std::string> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < n and a[i][j] == '#';
    };

    std::set<std::set<std::pair<int, int>>> ans;
    auto add = [&](auto i, auto j, auto dx, auto dy)
    {
        std::set<std::pair<int, int>> points {
            {i, j}, {i + dy, j - dx}, {i + dx, j + dy}, {i + dx + dy, j - dx + dy}
        };

        for (auto [x, y] : points)
        {
            if (!safe(x, y))
                return;
        }

        if (points.size() == 4)
            ans.emplace(points);
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != '#')
                continue;

            for (int dx = -8; dx < n; dx++)
            {
                for (int dy = -8; dy < n; dy++)
                {
                    if (dx or dy)
                        add(i, j, dx, dy);
                }
            }
        }
    }

    std::cout << std::size(ans);
    
    return 0;
}