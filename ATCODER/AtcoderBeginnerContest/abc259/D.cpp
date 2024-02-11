#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
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

    i64 sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    std::vector<std::tuple<i64, i64, i64>> a(n);
    for (auto &[x, y, r] : a)
        std::cin >> x >> y >> r;

    auto distance = [&](i64 x1, i64 y1, i64 x2, i64 y2)
    {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    std::vector<i64> ons, ont;

    auto on_circle = [&](int i)
    {
        auto [x, y, r] = a[i];
        if (distance(x, y, sx, sy) == r * r)
            ons.push_back(i);
        if (distance(x, y, tx, ty) == r * r)
            ont.push_back(i);
    };

    DSU d(n);

    for (int i = 0; i < n; i++)
    {
        auto [x1, y1, r1] = a[i];
        on_circle(i);

        for (int j = i + 1; j < n; j++)
        {
            auto [x2, y2, r2] = a[j];

            if (distance(x2, y2, x1, y1) == (r1 - r2) * (r1 - r2))
                d.unite(i, j);
            else if (distance(x2, y2, x1, y1) <= (r1 + r2) * (r1 + r2)
                 and distance(x1, y1, x2, y2) >= (r1 - r2) * (r1 - r2))
                d.unite(i, j);
        }
    }
    for (auto s_ : ons)
    {
        for (auto t_ : ont)
        {
            if (d.same(s_, t_))
            {
                std::cout << "Yes\n";
                return 0;
            }
        }
    }

    std::cout << "No\n";
    
    return 0;
}