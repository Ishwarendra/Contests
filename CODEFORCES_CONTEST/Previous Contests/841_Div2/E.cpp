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
    i64 m;
    std::cin >> n >> m;

    std::vector<i64> dp(n + 1);
    for (int i = n - 1; i > 0; i--)
    {
        i64 sum = 0;
        for (i64 k = 1; k * i <= n; k++)
            sum += dp[k * i];

        i64 sz = n / i;
        dp[i] = sz * (sz - 1) / 2 - sum;
    }
    print(dp)
    i64 cost = 0;
    for (int g = n; g > 1 and m > 0; g--)
    {
        if (dp[g] == 0 or dp[g] < g - 1)
            continue;

        i64 have = dp[g] / (g - 1);
        if (have * (g - 1) > m)
        {
            i64 y = m / (g - 1);
            m -= y * (g - 1);
            cost += y * g;
        }
        else
        {
            m -= have * (g - 1);
            cost += have * g;
        }
    }

    if (m > 0)
        std::cout << "-1\n";
    else
        std::cout << cost << "\n";
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