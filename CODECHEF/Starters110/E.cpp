#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, h;
    std::cin >> n >> h;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::rbegin(a), std::rend(a));

    auto good = [&](int mid)
    {
        int need = 0;
        for (int i = 0; i < mid; i++)
            need += a[i];

        need += (mid + 1) * a.back();
        return need >= h;
    };

    int left = 0, right = n - 1;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
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