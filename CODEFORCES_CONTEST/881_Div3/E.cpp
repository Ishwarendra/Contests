#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)  
        std::cin >> l[i] >> r[i];

    int q;
    std::cin >> q;

    std::vector<int> query(q);
    for (int i = 0; i < q; i++)
        std::cin >> query[i];

    int left = 1, right = q;
    int ans = -1;

    auto good = [&](int mid)
    {
        std::vector a(n + 1, 0);
        for (int i = 0; i < mid; i++)
            a[query[i]] = 1;

        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];

        for (int i = 0; i < m; i++)
        {
            auto sum = a[r[i]] - a[l[i] - 1];
            auto len = r[i] - l[i] + 1;

            if (sum >= len / 2 + 1)
                return true;
        }

        return false;
    };

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
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