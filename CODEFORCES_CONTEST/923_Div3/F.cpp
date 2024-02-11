#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
}; 

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> edges(m);
    for (auto &[w, u, v] : edges) 
    {
        std::cin >> u >> v >> w;
        u--, v--;
    }

    std::sort(std::rbegin(edges), std::rend(edges));
    auto min = edges[0];
    DSU dsu(n);

    std::vector<std::vector<int>> adj(n);

    for (auto &[w, u, v] : edges)
    {
        if (!dsu.unite(u, v))
            min = std::min(min, std::array {w, u, v});
        else
        {
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }

    auto bfs = [&](int src, int sink)
    {
        std::queue<int> q;
        q.emplace(src);

        std::vector<int> d(n, n + 1), p(n, -1);
        d[src] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] == n + 1)
                {
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.emplace(v);
                }
            }
        }

        int u = sink;
        std::vector<int> path;
        while (u != -1)
        {
            path.emplace_back(u);
            u = p[u];
        }

        return path;
    };

    auto cycle = bfs(min[1], min[2]);
    int sz = std::size(cycle);
    std::cout << min[0] << " " << sz << "\n";

    for (int i = 0; i < sz; i++)
        std::cout << cycle[i] + 1 << " \n"[i == sz - 1];
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