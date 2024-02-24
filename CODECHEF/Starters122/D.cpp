#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        a[i] *= 2;
    }

    auto good = [&](i64 mid)
    {
        std::vector<i64> dp(n, inf);
        for (int i = 1; i < n; i++)
        {}
    };

    i64 left = 1, right = 2e9;
    i64 ans = 2e9;

    while (left <= right)
    {
        i64 mid = (left + right) / 2;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
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