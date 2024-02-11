#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 base = 1e12;
constexpr i64 inf = 1e18;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    if (n == 1)
    {
        std::cout << "0\n";
        return;
    }

    // dp[i][0] => ends with 0
    // dp[i][1] => ends with 01
    // dp[i][2] => ends with 11
    // dp[i][3] => ends with 10? Not valid
    std::vector dp(n, std::array<i64, 3>{inf, inf, inf});  
    if (s[0] == '0')
        dp[0][0] = 0;
    else
    {
        dp[0][0] = base + 1;
        dp[0][1] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + base;
            dp[i][2] = dp[i - 1][2] + base + 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0] + base + 1;
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1] + base + 1);
            dp[i][2] = std::min(dp[i - 1][1], dp[i - 1][2]);
        }
    }

    std::cout << *std::min_element(std::begin(dp.back()), std::end(dp.back())) << "\n";
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