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
    
    i64 d;
    std::cin >> d;

    const int max = 2e6;
    auto ans = d;

    for (int x = 1; x <= max; x++)
    {
        if (1LL * x * x > d)
            break;

        int left = 0, right = max;
        i64 cur = 0;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (1LL * mid * mid >= d - 1LL * x * x)
                cur = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        ans = std::min(ans, std::abs(1LL * x * x + cur * cur - d));

        left = 0, right = max;
        cur = 0;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (1LL * mid * mid <= d - 1LL * x * x)
                cur = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        
        ans = std::min(ans, std::abs(1LL * x * x + cur * cur - d));
    }

    std::cout << ans;
    
    return 0;
}