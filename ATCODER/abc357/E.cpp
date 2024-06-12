#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        adj[i].emplace_back(a - 1);
        radj[a - 1].emplace_back(i);
    }
    
    int time = 0;
    std::vector<int> tout(n, -1), vis(n, 0);
 
    auto dfs1 = [&](auto &&self, int u) -> void
    {
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (!vis[v])
                self(self, v);
        }
 
        tout[u] = time++;
    }; 
 
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs1(dfs1, i);
    }
 
    std::fill(std::begin(vis), std::end(vis), 0);
    std::vector<int> ord(n);
    std::iota(std::begin(ord), std::end(ord), 0);
 
    std::sort(std::begin(ord), std::end(ord), [&](int u, int v)
    {
        return tout[u] > tout[v];
    });
 
    std::vector<int> scc_num(n), nodes(n);
    auto dfs2 = [&](auto &&self, int u, int num) -> void
    {
        vis[u] = 1;
        scc_num[u] = num;
        nodes[num]++;
 
        for (int v : radj[u])
        {
            if (!vis[v])
                self(self, v, num);
        }
    }; 
 
    int cnt = 0;
    for (auto u : ord)
    {
        if (!vis[u])
            dfs2(dfs2, u, cnt++);
    }
 
    std::vector<std::vector<std::pair<int, int>>> g(cnt);
 
    for (int u = 0; u < n; u++)
    {
        for (int v : adj[u])
        {
            if (scc_num[u] != scc_num[v])
                g[scc_num[u]].emplace_back(scc_num[v], nodes[v]);
        }
    }
    
    std::vector<int> node_cnt(cnt);
    auto dfs3 = [&](auto &&self, int u, int p) -> void
    {
        vis[u] = 1;
        node_cnt[u] = nodes[u];
        for (auto [v, c] : g[u])
        {
            if (v == p)
                continue;
            
            self(self, v, u);
            node_cnt[u] += node_cnt[v];
        }
    };
    
    std::fill(std::begin(vis), std::end(vis), 0);
    for (int i = 0; i < cnt; i++)
    {
        if (!vis[i])
            dfs3(dfs3, i, i);
    }
    
    i64 ans = 0;
    for (int i = 0; i < cnt; i++)
        ans += 1LL * node_cnt[i] * nodes[i];
    
    std::cout << ans;
    
    return 0;
}