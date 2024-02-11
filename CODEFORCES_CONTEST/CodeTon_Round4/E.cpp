#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
public:
    std::vector<int> rnk, par;
    std::vector<std::vector<int>> comp;
    DSU(int n) : rnk(n, 1), par(n), comp(n) 
    { 
        std::iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++)
            comp[i].emplace_back(i);
    }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y, auto &adj, auto &a, auto &s)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;   
            for (auto u : comp[p2])             
            {
                comp[p1].emplace_back(u);
                for (auto v : adj[u])
                    s.insert({a[v], v, u}); // label, next node, from which comp
            }

            comp[p2].clear();
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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

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

    std::set<std::array<int, 3>> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int v : adj[i])
                s.insert({a[v], v, i});
        }
    }

    while (!s.empty())
    {
        auto [need, v, u] = *std::begin(s);
        s.erase(std::begin(s));

        int have = dsu.size(u);
        // print(u, v, need, have)
        if (have >= need)
            dsu.unite(u, v, adj, a, s);
    }
    // print(dsu.rnk)
    std::cout << (dsu.size(0) == n ? "YES\n" : "NO\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}