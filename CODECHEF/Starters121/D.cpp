#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::array<int, 2>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1 -1}};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::set<std::pair<int, int>> b, vis;

    auto safe = [&](int i, int j)
    {
        return 1 <= i and i <= n and 1 <= j and j <= n and !vis.count({i, j});
    };

    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        b.emplace(x, y);
    }

    auto bfs = [&](std::vector<std::pair<int, int>> &src, int ex, int ey)
    {
        std::queue<std::pair<int, int>> q;
        vis.clear();

        for (auto [x, y] : src)
        {
            q.emplace(x, y);
            vis.emplace(x, y);
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if ((x == ex or ex == -1) and (y == ey || ey == -1))
                return true;

            for (auto &[dx, dy] : dirs)
            {
                if (!safe(x + dx, y + dy))
                    continue;

                if (!b.count({x + dx, y + dy}))
                    continue;

                q.emplace(x + dx, y + dy);
                vis.emplace(x + dx, y + dy);
            }
        }

        return false;
    };

    std::vector<std::pair<int, int>> srcs;
    for (auto &[x, y] : b)
    {
        if (y == 1)
            srcs.emplace_back(x, y);
    }

    int ok = bfs(srcs, 1, -1) or bfs(srcs, -1, n);
    srcs.clear();

    for (auto &[x, y] : b)
    {
        if (x == n)
            srcs.emplace_back(x, y);
    }

    ok = ok or bfs(srcs, -1, n) or bfs(srcs, 1, -1);
    std::cout << (!ok ? "YES\n" : "NO\n");
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