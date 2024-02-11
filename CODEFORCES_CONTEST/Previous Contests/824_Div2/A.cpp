#include <bits/stdc++.h>

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

    int left = 0, right = 1e9;  
    int ans = 0;

    auto good = [&](int mid)
    {
        return 6LL + 3LL * mid <=  1LL * n;
    };

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
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