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

    std::map<int, std::vector<int>> pos;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]].emplace_back(i);
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    constexpr int inf = 1e9;
    std::vector<int> d(n, -inf), vis(n);
    d[0] = 1;

    for (auto &[num, p] : pos)
    {
        std::sort(std::begin(p), std::end(p), [&](int i, int j)
        {
            return d[i] > d[j];
        });

        for (int u : p)
        {
            if (vis[u])
                continue;

            std::queue<int> q;
            q.emplace(u);
            vis[u] = 1;

            while (!q.empty())
            {
                auto u = q.front();
                q.pop();

                for (int v : adj[u])
                {
                    if (vis[v] || a[v] != a[u])
                        continue;
                    vis[v] = 1;
                    q.emplace(v);
                    d[v] = d[u];
                }
            }
        }

        for (int u : p)
        {
            for (int v : adj[u])
            {
                if (a[v] > a[u] and d[v] < d[u] + 1)
                    d[v] = d[u] + 1;
            }
        }
    }

    std::cout << std::max(0, d[n - 1]);

    return 0;
}