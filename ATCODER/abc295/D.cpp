#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector dp(n, std::array<int, 10>{});
    for (int i = 0; i < n; i++)
    {
        dp[i][s[i] - '0']++;
        if (i)
        {
            for (int j = 0; j < 10; j++)
                dp[i][j] += dp[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            dp[i][j] %= 2;
    }

    std::map<std::array<int, 10>, int> m;
    auto _ = std::array<int, 10>{};
    m[_]++;
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.count(dp[i]))
            ans += m[dp[i]];

        m[dp[i]]++;
    }

    std::cout << ans;
    
    return 0;
}