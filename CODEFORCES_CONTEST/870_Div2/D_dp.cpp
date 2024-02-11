#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector dp(n, std::array {-inf, -inf});
    dp[0][0] = a[0];
    dp[1][0] = std::max(a[0], a[1] + 1);
    dp[1][1] = a[0] + a[1];

    i64 ans = -inf;
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], 1LL * a[i] + i);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + a[i]);

        ans = std::max(ans, dp[i - 1][1] + a[i] - i);
    }

    print(dp)

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