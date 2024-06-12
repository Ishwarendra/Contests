#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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
    
    int n;
    std::cin >> n;

    DSU dsu(n);
    std::vector<std::array<int, 4>> ans;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        if (!dsu.unite(u, v))
            ans.push_back({u + 1, v + 1, 1, -1});
    }

    for (int i = 0, id = 0; i < n; i++)
    {
        if (!dsu.same(0, i))
        {
            dsu.unite(0, i);
            ans[id++][3] = i + 1;
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto &[i, j, u, v] : ans)
        std::cout << i << " " << j << " " << u << " " << v << "\n";
           
    return 0;
}
