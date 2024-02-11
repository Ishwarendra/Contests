#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> dp;
    std::function<int(int)> f = [&](int x)
    {
        if (x == m)
            return 1;
        if (x < m)
            return 0;

        if (dp.contains(x))
            return dp[x];

        dp[x] = 0;
        if (x % 3 == 0)
            dp[x] = f(x / 3) | f(2 * x / 3);
        return dp[x];
    };

    std::cout << (f(n) ? "YES" : "NO") << "\n";
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