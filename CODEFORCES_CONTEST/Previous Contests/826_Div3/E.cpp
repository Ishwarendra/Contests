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

    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i < n + 1; i++)  
    {    
        if (i + a[i - 1] <= n)
            dp[i + a[i - 1]] |= dp[i - 1];
        if (i - a[i - 1] - 1 >= 0 and dp[i - a[i - 1] - 1])
            dp[i] = 1;
    }
    
    std::cout << (dp[n] ? "YES\n" : "NO\n");
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