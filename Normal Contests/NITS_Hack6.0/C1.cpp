#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;

    auto where = [&](int l1, int r1, int l2, int r2)
    {
        // 0 -> disjoint, 1 -> inside, 2 -> intersect
        if (l2 > r1 || l1 > r2)
            return 0;

        if (l1 <= l2 and r2 <= r1)
            return 1;
        if (l2 <= l1 and r1 <= r2)
            return 1;

        return 2;
    };

    auto get = [&](int l1, int r1, int l2, int r2)
    {
        auto type = where(l1, r1, l2, r2);
        if (type == 1)
            return std::abs(l2 - l1) * 2 + std::abs(r2 - r1);
        else if (type == 2)
            return std::abs(l2 - l1) * 2 + std::abs(r2 - r1);

        if (r1 < l2)
            return std::abs(r2 - r1) + std::abs(l2 - l1) * 2;

        return std::abs(l2 - l1) * 2 + std::abs(r2 - r1);
    };

    std::map<std::string, std::vector<std::pair<int, int>>> pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            pos[s.substr(i, j - i + 1)].emplace_back(i, j);
    }

    while (q--)  
    {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        l1--, l2--;

        auto u = s.substr(l1, r1 - l1);
        auto v = s.substr(l2, r2 - l2);

        int ans = 10 * n;

        for (auto &[x1, y1] : pos[u])        
        {
            for (auto &[x2, y2] : pos[v])
            {
                print(x1, y1, x2, y2);
                ans = std::min(ans, get(x1, y1, x2, y2));
            }
        }

        std::cout << ans << "\n";
    }
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