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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (std::count(std::begin(a), std::end(a), 0) != 1)
    {
        std::cout << "NO\n";
        return;
    }

    std::vector<int> del(n);
    std::set<int> id;
    std::set<std::pair<int, int>> num;
    for (int i = 0; i < n; i++)
        id.emplace(i);

    auto prevOk = [&](int i)
    {
        auto it = id.lower_bound(i);
        if (it != std::begin(id))
        {
            --it;
            return (a[i] - a[*it]) == 1;
        }

        return false;
    };

    auto nextOk = [&](int i)
    {
        auto it = id.upper_bound(i);
        if (it != std::end(id))
            return (a[i] - a[*it]) == 1;

        return false;
    };

    for (int i = 0; i < n; i++)
    {
        if (prevOk(i) || nextOk(i))
            num.emplace(-a[i], i);
    }

    while (!num.empty())
    {
        auto [x, i] = *std::begin(num);
        num.erase(std::begin(num));
        id.erase(i);

        auto it = id.lower_bound(i);
        if (it != std::begin(id) and id.count(*--it))
        {
            if (prevOk(*it) || nextOk(*it))
                num.emplace(-a[*it], *it);
        }

        it = id.upper_bound(i);
        if (it != std::end(id) and id.count(*it))
        {
            auto it = id.upper_bound(i);
            if (prevOk(*it) || nextOk(*it))
                num.emplace(-a[*it], *it);
        }
    }

    std::cout << (std::size(id) == 1 ? "YES\n" : "NO\n");
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