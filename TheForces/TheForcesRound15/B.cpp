#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == 0 and x2 == 0)  
        std::cout << std::abs(y2 - y1) << "\n";
    else if (y1 == 0 and y2 == 0)
        std::cout << std::abs(x1 - x2) << "\n";
    else
    {
        double ans = 0;
        int r = 0;
        
        for (auto x : {x1, x2})
        {
            for (auto y : {y1, y2})
            {
                if (x != 0 and y != 0)
                    ans += std::abs(std::abs(x) - std::abs(y)), r = std::min(std::abs(x), std::abs(y));
            }
        }

        constexpr double pi = std::acos(-1);
        ans += pi * r / 2;
        std::cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(12);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}