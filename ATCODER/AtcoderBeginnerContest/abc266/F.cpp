#include <bits/stdc++.h>

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
    int n;
    std::cin >> n;

    DSU d(n);
    std::pair<int, int> edge;
    std::vector<int> adj[n];
    for (int i = 0; i < n; ++i)      
    {
        int u, v;
        std::cin >> u >> v;

        if (d.same(u, v))
            edge = {u, v};

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
        d.unite(u, v);
    }

    std::vector<int> cyc;
    std::set<int> cycle;

    std::vector<int> vis(n);
    std::function<void(int, int)> dfs;

    dfs = [&](int u, int p)
    {
        print(u, p)
        vis[u] = 1;

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v, u);
            else if (v != p)
            {
                print(u, v, p)
            }
        }
    };

    dfs(0, -1);

    int q;
    std::cin >> q;

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    
    while (t--)
        solve();
    
    return 0;
}