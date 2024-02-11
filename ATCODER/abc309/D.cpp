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
    
    int n1, n2, m;
    std::cin >> n1 >> n2 >> m;

    std::vector<int> adj[n1 + n2];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto bfs = [&](int src)
    {
        constexpr int inf = 1e9;
        std::vector<int> d(n1 + n2, inf);
        d[src] = 0;
        std::queue<int> q;
        q.emplace(src);

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] == inf)
                {
                    d[v] = d[u] + 1;
                    q.emplace(v);
                }
            }
        }

        return d;
    };

    auto d1 = bfs(0);
    auto dn = bfs(n1 + n2 - 1);

    int max1 = 0, maxn = 0;
    for (int i = 0; i < n1; i++)
        max1 = std::max(max1, d1[i]);
    for (int i = n1; i < n1 + n2; i++)
        maxn = std::max(maxn, dn[i]);
    
    std::cout << 1 + max1 + maxn;

    return 0;
}