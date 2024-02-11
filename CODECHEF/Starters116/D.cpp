#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void chmin(i64 &a, i64 b)
{
    if (a > b)
        a = b;
}

void solve()
{
    int n, x, z;
    std::cin >> n >> x >> z;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];


    std::vector dp(x, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        auto ndp = dp;
        for (int s = 0; s < x; s++)
        {
            if (dp[s] != inf)
                chmin(ndp[(s + a[i]) % x], dp[s] + a[i]);
        }

        std::swap(dp, ndp);
    }

    i64 ans = inf;
    for (int i = 0; i < x; i++)
    {
        if (dp[i] != inf and (z + dp[i]) % x == 0)
            ans = std::min(ans, (z + dp[i]) / x);
    }

    std::cout << (ans == inf ? -1 : ans) << "\n";
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