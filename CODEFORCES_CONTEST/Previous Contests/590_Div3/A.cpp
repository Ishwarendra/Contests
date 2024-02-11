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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    auto good = [&](int mid)
    {
        i64 cur = 1LL * mid * n;
        return cur >= sum;
    };

    int left = 1, right = 1e9;
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

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}