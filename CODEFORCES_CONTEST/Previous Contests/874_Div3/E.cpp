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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int cc = n;

    DSU dsu(n);
    std::vector<int> adj[n], indeg(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        cc -= dsu.unite(i, a[i]);

        adj[i].emplace_back(a[i]);
        indeg[a[i]]++;
    }

    int cycle = 0;
    int found = 0;
    std::vector<int> vis(n);
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v, u);
            else if (v != p and a[a[v]] != v)
                found = 1;
        }
    };

    int add = 0;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            found = 0;
            dfs(i, i);
            if (found)
                cycle++;
            else
                add |= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            found = 0;
            dfs(i, i);
            if (found)
                cycle++;
            else
                add |= 1;
        }
    }

    std::cout << cycle + add << " " << cc << "\n";
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