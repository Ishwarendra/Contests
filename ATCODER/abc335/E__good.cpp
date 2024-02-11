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

    DSU dsu(n);
    for (auto &[num, p] : pos)
    {
        for (int i = 1; i < std::size(p); i++)
            dsu.unite(p[i - 1], p[i]);
    }

    std::vector<int> d(n);
    d[dsu.get(0)] = 1;
    std::queue<int> q;
    q.emplace(0);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (a[v] < a[u])
                continue;

            int w = a[v] > a[u];
            if (d[dsu.get(v)] < d[dsu.get(u)] + w)
            {
                d[dsu.get(v)] = d[dsu.get(u)] + w;
                q.emplace(v);
            }
        }
    }

    std::cout << d[dsu.get(n - 1)];

    return 0;
}