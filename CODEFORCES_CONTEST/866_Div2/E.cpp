#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 2e5 + 2;
std::set<int> adj[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace(--v);
        adj[v].emplace(u);
    }

    for (int i = 0; i < n; i++)
    {
        for (auto first : adj[i])
        {
            for (auto v : adj[first])
            {
                if (v == i)
                    continue;

                adj[v].emplace(i);
                adj[i].emplace(v);
            }
        }
    }

    std::vector<int> vis(n), par(n, -1);
    int cycle = 0;
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        vis[u] = 1;
        par[u] = p;

        for (auto v : adj[u])
        {
            if (!vis[v])
                dfs(v, u);
            else if (v != p)
                
        }
    };
    
    return 0;
}