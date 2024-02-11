#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::array<i64, 2>> a(n);
    for (auto &[s, e] : a)
    {
        std::cin >> s >> e;
        e += s;
    }

    std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y)
    {
        return x[0] < y[0];
    });

    i64 t = 0;
    std::multiset<i64> m;
    int pos = 0, ans = 0;

    while (pos < n or !m.empty())
    {
        if (pos < n and m.empty())
            m.emplace(a[pos][1]), t = a[pos++][0];

        while (pos < n and t >= a[pos][0])
            m.emplace(a[pos][1]), pos++;

        while (!m.empty())
        {
            auto end = *std::begin(m);
            if (end < t)
                m.erase(std::begin(m));
            else
                break;
        }

        if (!m.empty())
        {
            ans++;
            m.erase(std::begin(m));
            t++;
        }
    }

    std::cout << ans;

    return 0;
}