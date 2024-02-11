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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    DSU dsu(n);
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j += k)
            dsu.unite(i, j);
    }

    auto b = a;
    std::sort(std::begin(b), std::end(b));

    std::vector<std::pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] and !dsu.same(i, pos[b[i]]))
            m.emplace_back(i, dsu.get(pos[b[i]]));
    }

    if (std::size(m) == 0)
        std::cout << "0\n";
    else if (std::size(m) > 2)
        std::cout << "-1\n";
    else
        std::cout << "1\n";
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