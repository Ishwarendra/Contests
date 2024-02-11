#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;
constexpr i64 inf = 1e15;


void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<i64> dp(31, -inf); // 1e9 - 2^30 < 0
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector<i64> ndp(31, -inf);

        for (int j = 0; j < 31; j++)
        {
            // good
            ndp[j] = std::max(ndp[j], dp[j] + (a[i] / (1 << j)) - k);

            // bad
            if (j + 1 < 31)
                ndp[j + 1] = std::max(ndp[j + 1], dp[j] + (a[i] / (1 << (j + 1))));
            else
                ndp[j] = std::max(ndp[j], dp[j]);
        }

        std::swap(dp, ndp);
    }

    std::cout << *std::max_element(std::begin(dp), std::end(dp)) << "\n";
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