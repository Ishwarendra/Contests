#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    std::vector dp(n, std::vector<i64>(k, inf));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1LL * (a[i] - a[0]) * (a[i] - a[0]);

    auto sq = [&](auto x)
    {
        return 1LL * x * x;
    };

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
            // closest?
            int closest = std::upper_bound(std::begin(a), std::end(a), 1LL * j * a[i] / (j + 1)) - std::begin(a);
            print(a[i], i, closest)
            for (int p = std::min(i - 1, closest + 100); p >= std::max(0, closest - 100); p--)
                dp[i][j] = std::min(dp[i][j], dp[p][j - 1] + sq(a[i] - a[p + 1]));
        }
    }

    std::cout << dp[n - 1][k - 1] << "\n";

    return 0;
}