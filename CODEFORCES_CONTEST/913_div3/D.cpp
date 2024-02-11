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

    std::vector a(n, std::array<int, 2>());
    for (auto &[l, r] : a)  
        std::cin >> l >> r;

    int left = 0, right = 1e9;
    int ans = 1e9;

    auto good = [&](int k)
    {
        int L = 0, R = 0;
        for (auto &[l, r] : a)
        {
            L -= k;
            R += k;
            L = std::max(l, L);
            R = std::min(R, r);

            if (R < l or L > r)
                return false;
        }

        return true;
    };

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

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