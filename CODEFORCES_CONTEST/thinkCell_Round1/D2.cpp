#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<i64> dp(n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        auto ch = s[i - 1];
        if (ch == '0')
            dp[i] = dp[i - 1];
        else
        {
            int id = std::max(0, i - 3);
            dp[i] = dp[id] + i;
        }
    }

    std::cout << std::accumulate(std::begin(dp), std::end(dp), 0LL) << "\n";
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