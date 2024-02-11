#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, st, en;
    std::cin >> n >> st >> en;
    st--, en--;
    std::swap(st, en);

    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    if (st == en)
    {
        std::cout << "NO\n";
        return;
    }

    std::vector<int> vis(n);
    std::array<int, 2> cyc{-1, -1};

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        vis[u] = 1;

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v, u);
            else if (v != p)
                cyc = {u, v};
        }
        
    }; dfs(0, 0);

    assert(cyc[0] != -1);
    std::fill(std::begin(vis), std::end(vis), 0);
    std::vector<int> temp, cycle_nodes;

    dfs = [&](int u, int p) -> void
    {
        vis[u] = 1;
        temp.emplace_back(u);
        if (u == cyc[1])
        {
            cycle_nodes = temp;
            return;
        }

        for (int v : adj[u])
        {
            if (!vis[v] and v != p)
                dfs(v, u);
        }

        temp.pop_back();
    }; dfs(cyc[0], cyc[1]);

    constexpr int inf = 1e9;

    std::sort(std::begin(cycle_nodes), std::end(cycle_nodes));
    auto bfs = [&](int src)
    {
        std::vector<int> d(n, inf);
        std::queue<int> q;
        q.emplace(src);
        d[src] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] == inf)
                {
                    q.emplace(v);
                    d[v] = d[u] + 1;
                }
            }
        }

        return d;
    };

    auto ds = bfs(st);
    auto dt = bfs(en);

    std::array<int, 2> mins {inf, -1};
    for (int u : cycle_nodes)
    {
        if (mins[0] > ds[u])
            mins = {ds[u], u};
    }

    int mint = dt[mins[1]];

    std::cout << (mins[0] < mint ? "YES\n" : "NO\n");
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