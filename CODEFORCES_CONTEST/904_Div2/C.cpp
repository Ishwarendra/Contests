#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 2>> a;
    for (int i = 0; i < n; i++)  
    {
        int l, r;
        std::cin >> l >> r;

        if (l == 1 and r == m)
            continue;
        a.push_back({l, r});
    }

    std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y)
    {
        return std::array {x[1], -x[0]} < std::array {y[1], -y[0]};
    });

    n = std::size(a);
    int ans = 0;    
    std::multiset<std::array<int, 3>> in;

    auto get = [&]()
    {
        int cur = 0;
        std::vector<std::array<int, 3>> event;

        for (auto &[l, r, id] : in)
        {
            event.push_back({l, -1, id});
            event.push_back({r, 1, id});
        }

        std::sort(std::begin(event), std::end(event));

        std::set<int> ongoing;
        for (auto [l, t, id] : event)
        {
            if (t == -1)
                ongoing.emplace(id);
            else
                ongoing.erase(id);

            cur = std::max<int>(cur, std::size(ongoing));
        }

        return cur;
    };

    for (int i = 0; i < n;)
    {
        auto [l, r] = a[i];
        if (r == m)
        {
            while (!in.empty())
            {
                auto [st, en, _] = *std::begin(in);
                if (st == 1)
                    in.erase(std::begin(in));
                else
                    break;
            }

            while (i < n)
                in.insert({a[i][0], a[i][1], i}), i++;

            ans = std::max(ans, get());
            break;
        }
        else
        {
            while (i < n and a[i][1] != m)
                in.insert({a[i][0], a[i][1], i}), i++;

            ans = std::max(ans, get());
        }
    }

    std::cout << ans << "\n";
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