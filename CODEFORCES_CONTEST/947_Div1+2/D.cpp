#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;
    
    std::vector adj(n, std::vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> path, nodes;
    auto dfs1 = [&](auto &&dfs, int u, int p) -> void
    {
        nodes.emplace_back(u);
        if (u == b)
            path = nodes;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
        }
        nodes.pop_back();
    }; dfs1(dfs1, a, a);
    
    int sz = std::size(path);
    int root = path[(sz - 1) / 2];
    // print(root, sz, path)
    int max = 0;
    
    auto dfs2 = [&](auto &&dfs, int u, int p, int dist) -> void
    {
        max = std::max(max, dist);
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u, dist + 1);
        }
    }; dfs2(dfs2, root, root, 0);

    std::cout << 2 * (n - 1) - max + sz / 2 << "\n";
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