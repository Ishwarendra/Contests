#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, l, t;
    i64 p;
    std::cin >> n >> p >> l >> t;

    int left = 1, right = n;
    int ans = 0;

    auto good = [&](int mid)
    {
        i64 task = std::min((n + 6) / 7, 2 * mid);
        i64 lesson = mid;
        return task * t + lesson * l >= p;
    };

    while (left <= right)  
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << n - ans << "\n";
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