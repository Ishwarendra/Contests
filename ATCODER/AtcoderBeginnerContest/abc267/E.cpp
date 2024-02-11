#include <bits/stdc++.h>

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

    std::vector<int> a(n);
    std::vector<std::set<int>> adj(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace(--v);
        adj[v].emplace(u);
    }

    std::vector<i64> sum(n);

    for (int i = 0; i < n; ++i)
    {
        for (int v : adj[i])
            sum[i] += a[v];
    }

    std::multiset<std::array<i64, 2>> q;
    for (int i = 0; i < n; ++i) 
        q.insert({sum[i], i64(i)});

    i64 cost = 0;
    while (!q.empty())
    {
        auto [c, u] = *std::begin(q);
        q.erase(std::begin(q));

        cost = std::max(cost, c);

        for (int v : adj[u])
        {
            auto it = q.find({sum[v], v});
            if (it != std::end(q))
            {
                q.erase(it);
                sum[v] -= a[u];
                q.insert({sum[v], v});
            }
        }
    }

    std::cout << cost;

    return 0;
}