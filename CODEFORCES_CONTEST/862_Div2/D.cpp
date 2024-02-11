#include "bits/stdc++.h"

#undef LOCAL

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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    std::vector<int> d(n, -1), dd(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    std::function<void(int, int, std::vector<int>&)> dfs = [&](int u, int p, std::vector<int> &dist)
    {
        dist[u] = dist[p] + 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u, dist);
        }
    };

    dfs(0, 0, d);
    int droot = std::max_element(std::begin(d), std::end(d)) - std::begin(d);
    dfs(droot, droot, dd);
    int droot2 = std::max_element(std::begin(dd), std::end(dd)) - std::begin(dd);

    std::fill(std::begin(d), std::end(d), -1);
    dfs(droot2, droot2, d);
    int cc = n;
    int dia = dd[droot2];

    print(droot, dd)
    print(droot2, d)
    std::vector<int> ans(n, 1);
    for (int i = n; i >= dia + 1; i--)
        ans[i - 1] = n;

    DSU dsu(n);

    std::map<int, std::vector<int>> one, two;
    for (int i = 0; i < n; i++)
    {
        one[dd[i]].emplace_back(i);
        two[d[i]].emplace_back(i);
    }
    
    for (int i = dia; i > 0; i--)
    {
        for (auto x : one[i])
            cc -= dsu.unite(droot, x);
        for (auto x : two[i])
            cc -= dsu.unite(droot2, x);

        ans[i - 1] = cc;
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}