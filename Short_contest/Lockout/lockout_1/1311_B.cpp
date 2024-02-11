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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), p(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        std::cin >> p[i];
        p[i]--;
    }

    DSU dsu(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int x = p[i];
        int y = p[i] + 1;

        dsu.unite(x, y);
    }

    auto b = a;
    std::sort(std::begin(b), std::end(b));

    auto find = [&](int x, int st)
    {
        for (int i = st; i < n; ++i)
            if (a[i] == x)
                return i;

        return n;
    };

    for (int i = 0; i < n; ++i)
    {
        auto cur = b[i];
        auto id = find(cur, i);

        if (!dsu.same(id, i))
        {
            std::cout << "NO\n";
            return;
        }

        std::swap(a[i], a[id]);
    }

    std::cout << "YES\n";
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