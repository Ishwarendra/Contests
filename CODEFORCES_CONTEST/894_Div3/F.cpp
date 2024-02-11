#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e6 + 1;

void solve()
{
    int n, w, f;
    std::cin >> w >> f >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int total = std::accumulate(std::begin(a), std::end(a), 0);
    std::bitset<N> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        dp |= dp << a[i];

    auto good = [&](int mid) -> bool
    {
        i64 water = 1LL * w * mid;
        i64 fire = 1LL * f * mid;

        if (water >= total or fire >= total)
            return true;

        auto [min, max] = std::minmax(water, fire);
        for (int x = 0; x < N; x++)
        {
            if (dp[x])
            {
                int min1 = x, max1 = total - x;
                if (min >= min1 and max >= max1)
                    return true;
            }
        }

        return false;
    };

    int left = 1, right = 1e6 + 10;
    int ans = 0;

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