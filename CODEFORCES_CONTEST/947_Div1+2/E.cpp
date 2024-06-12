#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Observations:
 * 1. 0 or 1 black nodes in total => handle separately
 * 2. exactly 2 black nodes have black degree = 1
 * 3. all other black nodes should have black degree = 2
 * ---
 * 1. exactly 2 black nodes have 1 black parent (+ child) node.
 * 2. no black node has more than 2 black child (+ parent) node.
 * 3. only lca(end1, end2) can have white parent.
 */

void solve()
{
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> c(n);  
    for (int i = 0; i < n; i++)
        std::cin >> c[i];
    
    std::vector adj(n, std::vector<int>());
    std::vector<int> black_deg(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        
        if (c[u] == 1)
            black_deg[v]++;
        if (c[v] == 1)
            black_deg[u]++;
    }
    
    std::vector<int> par(n, 0), bcnt(n, 0);
    auto dfs = [&](auto &self, int u, int p) -> void
    {
        par[u] = p;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
        }
    }; dfs(dfs, 0, 0);
    
    int black = std::accumulate(std::begin(c), std::end(c), 0);
    
    std::array<int, 4> cnt{};
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 1)
            cnt[std::min(3, black_deg[i])]++;
        bcnt[i] = std::min(3, black_deg[i]);
    }
    
    while (q--)
    {
        int u;
        std::cin >> u;
        u--;
        
        if (c[u] == 0)
        {
            black++;
            if (bcnt[par[u]] < 3)
            {
                cnt[bcnt[par[u]]]--;
                bcnt[par[u]]++;
                cnt[bcnt[par[u]]]++;
            }
            
            if (black <= 1)
            {
                std::cout << (black == 1 ? "Yes\n" : "No\n");
                continue;
            }
            
            if (cnt[0] == 0 and cnt[1] == 2 and cnt[3] == 0)
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
        }
        else
        {
            black--;
        }
    }
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