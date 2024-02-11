#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    int left = 1, right = 2e9;
    i64 ans = 0;

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
        if (1LL * mid * (mid - 1) / 2 <= n)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    ans += n - ans * (ans - 1) / 2;
    std::cout << ans << "\n";
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