#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::set<std::pair<i64, int>> q;
    std::vector<i64> dist(n, inf);

    for (auto [v, w] : adj[0])
    {
        dist[v] = w;
        q.emplace(dist[v], v);
    }

    dist[0] = 0;
    i64 sum = 0;

    std::vector<std::pair<std::string, i64>> ans;
    auto s = std::string(n, '0');
    s[0] = '1';

    bool possible = false;
    while (!q.empty() and s.back() != '1')
    {
        auto [d, u] = *std::begin(q);
        q.erase(std::begin(q));

        if (std::size(ans) < n * n and d != sum)
            ans.emplace_back(s, d - sum);

        if (u == n - 1)
            possible = true;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                q.erase({dist[v], v});
                dist[v] = d + w;
                q.emplace(dist[v], v);
            }
        }

        s[u] = '1';
        sum = d;
    }

    if (!possible)
        std::cout << "inf";
    else
    {
        std::cout << sum << " " << std::size(ans) << "\n";
        for (auto [x, y] : ans)
            std::cout << x << " " << y << "\n";
    }

    return 0;
}