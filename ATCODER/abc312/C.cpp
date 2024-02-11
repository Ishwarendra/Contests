#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    auto good = [&](int mid)
    {
        int buyers = 0, sellers = 0;
        for (int i = 0; i < n; i++)
            sellers += mid >= a[i];
        for (int i = 0; i < m; i++)
            buyers += mid <= b[i];

        return sellers >= buyers;
    };

    int left = 0, right = 1e9 + 1;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}