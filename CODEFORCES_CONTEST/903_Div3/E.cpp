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

    std::vector<int> dp(n + 1, 0);
    std::iota(std::begin(dp), std::end(dp), 0);

    auto chmin = [&](int &x, int y)
    {
        if (x > y)
            x = y;
    };

    for (int i = 1; i <= n; i++)
    {
        chmin(dp[i], dp[i - 1] + 1);
        if (i + a[i - 1] <= n)
            chmin(dp[i + a[i - 1]], dp[i - 1]);
    }
    
    std::cout << dp[n] << "\n";
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