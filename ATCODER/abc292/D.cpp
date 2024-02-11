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

    std::vector<int> adj[n], deg(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }

    std::vector<int> vis(n);

    int can = 0;
    int cycle = 0;

    std::function<void(int, int, std::vector<int> &)> dfs;
    dfs = [&](int u, int p, std::vector<int> &temp)
    {
        vis[u] = 1;
        temp.emplace_back(u);

        for (auto v : adj[u])
        {
            if (!vis[v])
                dfs(v, u, temp);
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            std::vector<int> nodes;
            dfs(i, -1, nodes);

            int sum = 0;
            for (auto u : nodes)
                sum += deg[u];

            if (sum != 2 * std::size(nodes))
            {
                std::cout << "No\n";
                return 0;
            }
        }
    }

    std::cout << "Yes\n";
    
    return 0;
}