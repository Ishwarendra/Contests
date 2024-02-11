#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::vector<std::pair<int, int>> dirs2 {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto bound = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto safe = [&](int i, int j)
    {
        if (!bound(i, j))
            return false;

        for (auto [dx, dy] : dirs)
        {
            if (bound(i + dx, j + dy) and a[i + dx][j + dy] == '#')
                return false;
        }

        return true;
    };

    auto wt = [&](int i, int j)-> int
    {
        assert(bound(i, j));
        return a[i][j] != '#'; // cactus is fwwee ride
    };

    constexpr int inf = 1e9;

    std::vector distance(n, std::vector<int>(m, inf));
    std::vector par(n, std::vector<std::array<int, 2>>(m, {-1, -1}));
    auto bfs = [&]()
    {
        std::set<std::array<int, 3>> q;

        for (int i = 0; i < n; i++)
        {
            if (safe(i, 0))
            {
                q.insert({wt(i, 0), i, 0});
                distance[i][0] = wt(i, 0);
            }
        }

        while (!q.empty())
        {
            auto [d, x, y] = *std::begin(q);
            q.erase(std::begin(q));

            for (auto [dx, dy] : dirs2)
            {
                if (!safe(x + dx, y + dy))
                    continue;

                if (distance[x + dx][y + dy] > distance[x][y] + wt(x + dx, y + dy))
                {
                    q.erase({distance[x + dx][y + dy], x + dx, y + dy});
                    distance[x + dx][y + dy] = distance[x][y] + wt(x + dx, y + dy);
                    par[x + dx][y + dy] = {x, y};
                    q.insert({distance[x + dx][y + dy], x + dx, y + dy});
                }
            }
        }
    }; bfs();

    auto min_id = 0;
    for (int row = 1; row < n; row++)
    {
        if (distance[min_id][m - 1] > distance[row][m - 1])
            min_id = row;
    }

    if (distance[min_id][m - 1] >= inf)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        int col = m - 1;

        while (par[min_id][col][0] != -1)
        {
            a[min_id][col] = '#';
            auto [x, y] = par[min_id][col];
            min_id = x;
            col = y;
        }

        a[min_id][col] = '#';

        for (int i = 0; i < n; i++)
            std::cout << a[i] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}