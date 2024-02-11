#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 2e18; 

std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    std::vector<std::string> geese(n);
    for (int i = 0; i < n; i++)
        std::cin >> geese[i];

    auto safe = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    };

    std::set<std::tuple<i64, int, int>> s;
    std::vector dist(n, std::vector<i64>(m, inf));
    s.emplace(0, 0, 0);
    dist[0][0] = 0;

    while (!s.empty())
    {
        auto [d, x, y] = *std::begin(s);
        s.erase(std::begin(s));
        geese[x][y] = '0';

        for (auto [dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                continue;

            int cnt = 0;
            for (auto [dx2, dy2] : dirs)
            {
                if (!safe(x + dx + dx2, y + dy + dy2))
                    continue;
                x += dx + dx2, y += dy + dy2;
                if (geese[x][y] == '1')
                    cnt++;
                x -= dx + dx2, y -= dy + dy2;
            }

            if (dist[x + dx][y + dy] > dist[x][y] + a[x + dx][y + dy] + 1LL * cnt * k)
            {
                s.erase({dist[x + dx][y + dy], x + dx, y + dy});
                dist[x + dx][y + dy] = dist[x][y] + a[x + dx][y + dy] + 1LL * cnt * k;
                s.emplace(dist[x + dx][y + dy], x + dx, y + dy);
            }
        }
    }

    std::cout << dist[n - 1][m - 1] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}