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
    std::cin >> n;

    auto factor = [&](auto x)
    {
        int ans = 0;
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
                ans += 1 + (i != x / i);
        }

        return ans;
    };

    i64 ans = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        int p1 = i, p2 = n - i;
        ans += 1LL * factor(p1) * factor(p2);
    }

    std::cout << ans;
    
    return 0;
}