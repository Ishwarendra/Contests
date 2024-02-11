#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::array<i64, 2>());
    for (int i = 0; i < n; i++)
        std::cin >> a[i][0];
    for (int i = 0; i < n; i++)
        std::cin >> a[i][1];

    std::vector<i64> b;
    b.emplace_back(a.front()[0] - 1);

    i64 max = 0;
    for (int i = 0; i < n; i++)
    {
        b.emplace_back(a[i][1] - a[i][0] + 1);
        max += a[i][1] - a[i][0] + 1;

        if (i + 1 < n)
            b.emplace_back(a[i + 1][0] - a[i][1] - 1);
    }

    if (max < k)
    {
        std::cout << "-1\n";
        return;
    }

    i64 ans = 1e18;
    n = std::size(b);
    
    i64 sum = 0, cover = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        sum += b[i];
        cover += 1LL * (i % 2) * b[i];
        one += (i % 2) and (b[i] == 1);

        if (cover < k)
            continue;

        i64 extra = std::min(one, cover - k);
        i64 add = (i - 1) / 2 + 1 - extra;
        add *= 2;
        if (add < 0)
            add = 0;

        ans = std::min(ans, sum + (k + extra - cover) + add);
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