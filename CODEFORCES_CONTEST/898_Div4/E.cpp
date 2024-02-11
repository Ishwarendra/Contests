#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 left = 0, right = 1e15;
    i64 ans = 0;

    auto good = [&](i64 mid)
    {
        i64 need = 0;
        for (int i = 0; i < n; i++)
        {
            need += std::max(0LL, mid - a[i]);
            if (need > x)
                return false;
        }

        return need <= x;
    };

    while (left <= right)
    {
        i64 mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << '\n';
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