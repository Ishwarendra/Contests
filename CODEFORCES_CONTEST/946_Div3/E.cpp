#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18L;

void solve()
{
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> c(n), h(n);
    for (int i = 0; i < n; i++)  
        std::cin >> c[i] >> h[i];
    
    int sum = std::accumulate(std::begin(h), std::end(h), 0);
    std::vector<i64> dp(sum + 1, inf);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++)
    {
        std::vector<i64> ndp(sum + 1, inf);
        for (int s = 0; s <= sum; s++)
        {
            if (dp[s] <= std::max(0LL, (i - 1LL) * x))
            {
                ndp[s] = std::min(ndp[s], dp[s]);
                if (s + h[i] <= sum)
                    ndp[s + h[i]] = std::min(ndp[s + h[i]], dp[s] + c[i]);
            }
        }
        
        std::swap(dp, ndp);
    }
    
    int ans = 0;
    for (int s = 1; s <= sum; s++)
    {
        if (dp[s] <= (n - 1LL) * x)
            ans = s;
    }
    
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