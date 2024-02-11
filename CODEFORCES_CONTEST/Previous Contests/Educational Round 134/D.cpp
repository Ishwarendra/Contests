#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    auto getBit = [&](int x, int pos)
    {
        assert(pos >= 0);
        return (x >> pos) & 1;
    };

    int ans = 0;
    std::queue<std::pair<std::vector<int>, std::vector<int>>> q;
    int bit = 30;

    auto change = [&](auto &x, auto &original)
    {
        for (int i = 0; i < std::ssize(x); i++)
            x[i] = original[x[i]];
    };

    auto check = [&](auto &x, auto &y, auto &q, auto &add)
    {
        std::vector<int> on_x, off_x, on_y, off_y;
        for (int i = 0; i < std::ssize(x); i++)
        {
            (getBit(x[i], bit) ? on_x : off_x).emplace_back(i);
            (getBit(y[i], bit) ? on_y : off_y).emplace_back(i);
        }

        if (std::size(on_x) != std::size(off_y))
        {
            add.push_back({x, y});
            return false;
        }
        change(on_x, x); change(on_y, y);
        change(off_x, x); change(off_y, y);

        if (!on_x.empty())
            add.push_back({on_x, off_y});
        if (!on_y.empty())
            add.push_back({on_y, off_x});

        return true;
    };

    q.push({a, b});
    while (bit >= 0)
    {
        int sz = std::size(q);
        bool can = true;
        std::vector<std::pair<std::vector<int>, std::vector<int>>> history, add;

        while (!q.empty())
        {
            auto [x, y] = q.front();
            history.emplace_back(q.front());
            q.pop();
            can &= check(x, y, q, add);
        }
        
        if (can)
        {
            ans |= (1 << bit);
            for (auto &_ : add)
                q.emplace(_);
        }
        else
        {
            for (auto &_ : history)
                q.emplace(_);
        }

        bit--;
    }

    std::cout << ans << "\n";
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