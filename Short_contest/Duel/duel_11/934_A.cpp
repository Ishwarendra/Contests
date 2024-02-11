#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int find(auto &a, bool neg, std::function<int(int, int)> cmp, int def)
{
    int n = std::size(a);
    int res = def;
    for (int i = 0; i < n; i++)
    {
        if (neg and a[i] > 0)
            continue;
        if (!neg and a[i] < 0)
            continue;

        if (res == def)
            res = a[i];
        else
            res = cmp(res, a[i]);
    }

    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    std::vector<int> c, d;

    constexpr int inf = 1e9 + 2;
    if (n > 8 and m > 4)
    {
        auto max = [&](int x, int y) { return std::max(x, y); };
        auto min = [&](int x, int y) { return std::min(x, y); };
        d.emplace_back(find(b, true, max, inf));
        d.emplace_back(find(b, true, min, inf));
        d.emplace_back(find(b, false, min, inf));
        d.emplace_back(find(b, false, max, inf));

        c.emplace_back(find(a, true, max, inf));
        c.emplace_back(find(a, true, min, inf));
        c.emplace_back(find(a, false, min, inf));
        c.emplace_back(find(a, false, max, inf));

        for (auto x : c)
        {
            auto it = std::find(std::begin(a), std::end(a), x);
            if (x != inf and it != std::end(a))
                a.erase(it);
        }

        c.emplace_back(find(a, true, max, inf));
        c.emplace_back(find(a, true, min, inf));
        c.emplace_back(find(a, false, min, inf));
        c.emplace_back(find(a, false, max, inf));
    }
    else
        c = a, d = b;
    
    i64 best = 1e18;
    n = std::size(c), m = std::size(d);
    for (int _ = 0; _ < n; _++)
    {
        if (c[_] == inf)
            continue;
        
        i64 cur_best = -1e18;
        for (int i = 0; i < n; i++)
        {
            if (i == _ or c[i] == inf)
                continue;

            for (auto x : d)
            {
                if (x == inf)
                    continue;
                cur_best = std::max(cur_best, 1LL * x * c[i]);
            }
        }

        best = std::min(best, cur_best);
    }

    std::cout << best;

    return 0;
}