#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool power2(int x)
{
    if (x == 0)
        return false;
    return __builtin_popcount(x) == 1;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    if (sum % n)
    {
        std::cout << "No\n";
        return;
    }

    auto find = [&](auto c)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                int x = (1 << i);
                int y = (1 << j);
                if (x - y == c)
                    return std::array {i, j};
            }
        }

        return std::array {-1, -1};
    };

    sum /= n;
    std::vector<std::array<int, 2>> req(n);
    for (int i = 0; i < n; i++)
    {
        req[i] = find(sum - a[i]);

        if (req[i][0] == -1)
        {
            std::cout << "No\n";
            return;
        }
    }

    std::set<std::array<int, 3>> s, uneligible;
    std::vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (req[i][0] == req[i][1] and req[i][0] == 0)
            pos.emplace_back(i);
        else
            s.insert({req[i][0], req[i][1], i});
    }

    while (!s.empty())
    {
        auto [x, y, id] = *std::begin(s);
        s.erase({x, y, id});

        if ((1 << y) > a[id])
        {
            uneligible.insert({x, y, id});
            continue;
        }

        auto it1 = s.lower_bound({y, -1, -1});
        if (it1 != std::end(s) and (*it1)[0] == y)
        {
            auto [x2, y2, id2] = *it1;
            s.erase(it1);
            a[id] -= 1 << y;
            a[id2] += 1 << y;

            if (a[id] != sum)
                uneligible.insert({x, -1, id});
            if (a[id2] != sum)
                s.insert({-1, y2, id2});
            continue;
        }
        it1 = uneligible.lower_bound({y, -1, -1});
        if (it1 != std::end(uneligible) and (*it1)[0] == y)
        {
            auto [x2, y2, id2] = *it1;
            uneligible.erase(it1);

            a[id] -= 1 << y;
            a[id2] += 1 << y;

            if (a[id] != sum)
                uneligible.insert({x, -1, id});
            if (a[id2] != sum)
                s.insert({-1, y2, id2});
            continue;
        }

        if (!pos.empty() and (1 << y) <= sum)
        {
            auto id2 = pos.back();
            pos.pop_back();
            s.insert({-1, y, id2});

            a[id] -= 1 << y;
            a[id2] += 1 << y;

            if (a[id] != sum)
                uneligible.insert({x, -1, id});
        }
        else
        {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
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