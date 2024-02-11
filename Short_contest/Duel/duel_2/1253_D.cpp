#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    std::vector<int> vis(n);
    int max, min;

    std::function<void(int)> dfs;
    dfs = [&](int u)
    {
        vis[u] = 1;
        max = std::max(u, max);
        min = std::min(u, min);

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v);
        }
    };

    std::vector<std::pair<int, int>> range;
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            max = -inf, min = inf;
            dfs(i);
            range.emplace_back(min, max);
        }
    }

    std::sort(std::begin(range), std::end(range));

    max = -inf, min = inf;
    int ans = 0;
    for (auto [st, en] : range)
    {
        if (min < st and st < max or min < en and en < max)
            ans++;

        min = std::min(min, st);
        max = std::max(max, en);
    }

    std::cout << ans << "\n";

    return 0;
}