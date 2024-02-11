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

    std::vector a(n, std::vector<int>());
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;
        a[i].assign(m, 0);

        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

        std::sort(std::begin(a[i]), std::end(a[i]));
        a[i].resize(2);
    }

    if (n == 1)
    {
        std::cout << a[0][0] << "\n";
        return;
    }

    std::sort(std::begin(a), std::end(a));

    std::array<i64, 2> ans{};

    ans[0] = a[0][0];
    for (int i = 1; i < n; i++)
        ans[0] += a[i][1];

    ans[1] = a[0][0] + a[0][1];
    std::sort(std::begin(a) + 1, std::end(a), [&](auto & x, auto & y)
    {
        return x[1] < y[1];
    });

    for (int i = 2; i < n; i++)
        ans[1] += a[i][1];

    std::cout << std::max(ans[0], ans[1]) << "\n";
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