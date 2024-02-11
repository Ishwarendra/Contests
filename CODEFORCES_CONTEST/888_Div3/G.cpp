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

    std::vector<int> h(n);
    for (int i = 0; i < n; i++)  
        std::cin >> h[i];

    std::vector<std::array<int, 3>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        edges.push_back({std::max(h[u], h[v]), u, v});
    }

    std::sort(std::begin(edges), std::end(edges));

    int q;
    std::cin >> q;
    std::vector<std::array<int, 4>> query(q);
    for (int pos = 0; auto &[e, u, v, id] : query)
    {
        std::cin >> u >> v >> e;
        u--, v--;
        id = pos++;
        e += h[u];
    }
    std::sort(std::begin(query), std::end(query));
    DSU dsu(n);

    std::vector<int> can(q);
    int i = 0;
    for (auto &[e, u, v, id] : query)
    {
        while (i < m and edges[i][0] <= e)
        {
            dsu.unite(edges[i][1], edges[i][2]);
            i++;
        }

        can[id] = dsu.same(u, v);
    }

    for (int i = 0; i < q; i++)
        std::cout << (can[i] ? "YES\n" : "NO\n");
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