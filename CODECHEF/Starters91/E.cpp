#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void chkmax(i64 &a, i64 b)
{
    if (a < b)
        a = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    const int M = std::min(60, k);
    std::vector dp(k + 1, std::vector<i64>(M + 1, -inf));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector st(k + 1, std::vector<i64>(M + 1, -inf));

        for (int x = 0; x <= k; x++)
        {
            st[x][M] = dp[x][M];
            for (int y = M - 1; y >= 0; y--)
                st[x][y] = std::max(st[x][y + 1], dp[x][y]);
        }

        std::vector ndp(k + 1, std::vector(M + 1, -inf));
        for (int x = 0; x <= k; x++)
        {
            for (int y = 0; y <= std::min(M, x); y++)
                chkmax(ndp[x][y], st[x - y][std::max(0, y - 1)] + 1LL * y * a[i]);
        }

        std::swap(ndp, dp);
    }

    i64 ans = 0;
    for (int x = 0; x <= k; x++)
    {
        for (int y = 0; y <= M; y++)
            ans = std::max(ans, dp[x][y]);
    }

    std::cout << ans;

    return 0;
}