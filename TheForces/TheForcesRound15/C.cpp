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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::array<int, 2> dp{};
    for (int i = 0; i < n; i++)
    {
        dp[0] += a[i][0] == '1';
        dp[1] += a[i][0] == '0';
    }

    for (int j = 1; j < m; j++)
    {
        std::array<int, 2> ndp {inf, inf};
        for (int cur = 0; cur < 2; cur++)
        {
            for (int prev = 0; prev < 2; prev++)
            {
                int cnt = 0;
                for (int i = 0; i < n; i++)
                    cnt += a[i][j - 1] - '0' == prev and a[i][j] - '0' != cur;
                ndp[cur] = std::min(ndp[cur], dp[prev] + 2 * cnt);
            }
        }

        std::swap(dp, ndp);
    }

    std::cout << std::min(dp[0], dp[1]) << "\n";
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