#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::set<i64> divisors(i64 x)
{
    std::set<i64> d;
    d.emplace(1);

    for (i64 i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            d.emplace(i);
    }

    return d;
}

void solve()
{
    auto intersect = [&](i64 x1, i64 y1, i64 x2, i64 y2) -> bool
    {
        // print(x1, y2, x2, y2)
        return (x1 <= x2 and x2 <= y1) or (x2 <= x1 and x1 <= y2);
    };

    i64 x, y;
    std::cin >> x >> y;
    auto s = divisors(y);

    i64 x1 = x / 2, y1 = (x + 1) / 2;
    std::vector<i64> d;
    for (auto i : s)
        d.emplace_back(i);

    const i64 inf = 1e14;
    
    for (int i = 0; i < std::size(d); i++)
    {
        i64 x2 = d[i];
        i64 y2 = y / x2;
        assert(y2 >= x2);

        if (!intersect(x1, y1, x2, y2))
        {
            std::cout << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n";
            return;
        }
    }

    std::cout << "-1\n";
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