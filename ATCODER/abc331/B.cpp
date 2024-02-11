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
    
    int n;
    std::array<int, 3> a{};
    std::cin >> n >> a[0] >> a[1] >> a[2];

    std::vector<int> dp(n + 1, int(1e9));
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int id = 0; auto x : {6, 8, 12})
            dp[std::min(n, i + x)] = std::min(dp[std::min(n, i + x)], dp[i] + a[id++]);
    }

    std::cout << dp[n];
    
    return 0;
}