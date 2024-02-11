#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    auto good = [&](int mid)
    {
        std::vector c(3, std::array<int, 2> {-inf, inf});
        int pos = 0;

        for (int i = 0; i < n; i++)
        {
            if (pos == 3)
                return false;

            c[pos][0] = std::max(c[pos][0], a[i] - mid);
            c[pos][1] = std::min(c[pos][1], a[i] + mid);
            if (c[pos][0] > c[pos][1])
                i--, pos++;
        }

        return true;
    };

    int left = 0, right = 1e9;
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