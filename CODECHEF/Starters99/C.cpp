#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    for (auto &[x, y] : a)
        std::cin >> x >> y;

    auto get = [&](int swap)
    {
        if (swap)
        {
            for (auto &[x, y] : a)
                std::swap(x, y);
        }

        std::sort(std::begin(a), std::end(a));
        std::multiset<int> m1, m2;
        for (int i = 0; i < n; i++)
            m2.emplace(a[i][1]);

        int ans = inf;
        for (int i = 0; i < n - 1; i++)
        {
            if (i > 0)
                m1.emplace(a[i - 1][1]);
            m2.erase(m2.find(a[i][1]));

            // all A | all B
            int max1 = *std::prev(std::end(m2));
            ans = std::min(ans, std::abs(max1 - a[i][0]));

            // some A, B | all B
            auto it = m1.lower_bound(std::max(max1, a[i][0]));
            if (it != std::end(m1))
                ans = std::min(ans, std::abs(*it - a[i][0]));
            if (it != std::begin(m1) and *std::prev(it) >= max1)
                ans = std::min(ans, std::abs(*std::prev(it) - a[i][0]));

            // all A | all B
            if (i > 0)
            {
                int max2 = a[i - 1][0];
                if (max2 >= max1)
                    ans = std::min(ans, std::abs(max2 - a[i][0]));
            }
        }

        m1.emplace(a[n - 2][1]);
        ans = std::min(ans, std::abs(a[n - 1][0] - a[n - 2][0]));
        auto it = m1.lower_bound(a[n - 1][0]);

        if (it != std::end(m1))
            ans = std::min(ans, std::abs(a[n - 1][0] - *it));
        if (it != std::begin(m1))
            ans = std::min(ans, std::abs(a[n - 1][0] - *std::prev(it)));

        return ans;
    };

    int ans = get(0);
    ans = std::min(ans, get(1));
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