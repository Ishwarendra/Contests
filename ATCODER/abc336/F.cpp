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

    std::vector a(n, std::vector(m, 0));
    auto b = a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
            b[i][j] = i * m + j;
            a[i][j]--;
        }
    }

    auto rotate = [&](auto &p, int x, int y)
    {
        auto q = p;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
                q[i + x][j + y] = p[n - 2 - i + x][m - 2 - j + y];
        }

        return q;
    };

    auto bfs = [&](std::vector<std::vector<int>> &src)
    {
        std::queue<std::vector<std::vector<int>>> q;
        q.emplace(src);
        std::map<std::vector<std::vector<int>>, int> d;
        d[src] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            if (d[u] == 10)
                break;

            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    auto v = rotate(u, x, y);
                    if (d.contains(v))
                        continue;
                    else
                    {
                        d[v] = d[u] + 1;
                        q.emplace(v);
                    }
                }
            }
        }

        return d;
    };


    auto ds = bfs(a);
    auto dt = bfs(b);

    int ans = 21;
    for (auto &[p, d] : ds)
    {
        if (dt.contains(p))
            ans = std::min(ans, ds[p] + dt[p]);
    }

    std::cout << (ans > 20 ? -1 : ans);

    return 0;
}