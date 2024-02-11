#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;  

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    if (n < k)
    {
        std::cout << 0 << "\n";
        return;
    }

    i64 left = 1, right = (std::accumulate(std::begin(a), std::end(a), 0LL)) / k + 10;
    i64 ans = 0;

    auto good = [&](i64 mid)
    {
        i64 sum = 0;
        for (int i = 0; i < n; i++)
            sum += std::min(mid, a[i] * 1LL);

        return sum >= mid * k;
    };

    while (left <= right)
    {
        i64 mid = (left + right) / 2;
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

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}