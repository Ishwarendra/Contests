#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1 << 30;

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
    
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i][0];
        a[i][1] = i;
    }

    std::sort(std::begin(a), std::end(a));
    std::vector<std::array<int, 3>> edges;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < std::min(i + 10, n); j++)
            edges.push_back({a[i][0] ^ a[j][0], a[i][1], a[j][1]});
    }

    std::sort(std::begin(edges), std::end(edges));
    DSU dsu(n);

    std::vector<std::vector<int>> adj(n); // MST

    for (auto &[w, u, v] : edges)
    {
        if (dsu.same(u, v))
            continue;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        dsu.unite(u, v);
    }

    std::vector<int> col(n, 1);
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        col[u] = col[p] ^ 1;
        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }
    }; dfs(0, 0);

    for (int i = 0; i < n; i++)
        std::cout << col[i];
    std::cout << "\n";
    
    return 0;
}