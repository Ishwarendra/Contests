#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto get(std::string &s)
{
    std::vector<std::pair<int, int>> a;
    int r = 0, u = 0;
    for (int i = 0; auto ch : s)
    {
        if (ch == 'L' or ch == 'R')
            r += (ch == 'L' ? -1 : 1);
        if (ch == 'U' or ch == 'D')
            u += (ch == 'D' ? -1 : 1);

        a.push_back({r, u});
        i++;
    }

    return a;
}

auto get(std::vector<std::pair<int, int>> &a)
{
    std::map<std::pair<int, int>, std::vector<int>> m;
    for (int i = 0; const auto &p : a)
        m[p].emplace_back(i++);
    return m;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    auto d = get(s);
    auto m = get(d);
    std::reverse(std::begin(s), std::end(s));
    auto dr = get(s);
    auto mr = get(dr);

    while (q--)
    {
        int x, y, l, r;
        std::cin >> x >> y >> l >> r;
        l--, r--;

        if (x == y and x == 0)
        {
            std::cout << "YES\n";
            continue;
        }

        int a = 0, b = 0;

        // 1 to l - 1
        if (l > 0)
        {
            auto &p = m[{x - a, y - b}];
            if (!p.empty() and p[0] < l)
            {
                std::cout << "YES\n";
                continue;
            }

            a += d[l - 1].first;
            b += d[l - 1].second;
        }

        int ddx = 0, ddy = 0;
        if (n - r - 2 >= 0)
        {
            ddx = dr[n - r - 2].first;
            ddy = dr[n - r - 2].second;
        }

        // reverse l to r
        auto &p = mr[{x - a + ddx, y - b + ddy}];
        if (!p.empty())
        {
            auto it = std::lower_bound(std::begin(p), std::end(p), n - r - 1);
            if (it != std::end(p) and *it <= n - l - 1)
            {
                std::cout << "YES\n";
                continue;
            }
        }

        auto [dx, dy] = dr[n - l - 1];
        if (n - r - 2 >= 0)
        {
            dx -= dr[n - r - 2].first;
            dy -= dr[n - r - 2].second;
        }

        a += dx, b += dy;
        ddx = ddy = 0;
        ddx += d[r].first;
        ddy += d[r].second;

        // r + 1 to n
        auto &q = m[{x - a + ddx, y - b + ddy}];
        if (!q.empty())
        {
            auto it = std::lower_bound(std::begin(q), std::end(q), r + 1);
            if (it != std::end(q) and *it < n)
            {
                std::cout << "YES\n";
                continue;
            }
        }

        std::cout << "NO\n";
    }
    
    return 0;
}