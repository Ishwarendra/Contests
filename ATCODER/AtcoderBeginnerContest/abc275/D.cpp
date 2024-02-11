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
    
    i64 n;
    std::cin >> n;

    std::map<i64, i64> dp;

    std::function<i64(i64)> f = [&](i64 x)
    {
        if (x == 0)
            return 1LL;
        if (dp.count(x))
            return dp[x];

        return dp[x] = f(x / 2) + f(x / 3);
    };

    std::cout << f(n);
    
    return 0;
}