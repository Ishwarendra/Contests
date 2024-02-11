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

    int left = 1, right = n;
    int ans = 0;

    auto good = [&](int mid)
    {
        std::multiset<int> m(std::begin(a), std::end(a));
        int have = 0;

        while (!m.empty() and *std::begin(m) <= mid - have)
        {
            // biggest element I can remove
            auto it = m.upper_bound(mid - have);
            if (it == std::begin(m))
                return have >= mid;

            m.erase(--it);
            have++;

            if (m.empty())
                return have >= mid;

            // smallest element he can make unusable
            // x + (mid - have + 1) > mid - have
            it = std::begin(m);

            auto add = *it + mid - have;
            m.erase(it);
            m.emplace(add);

            if (have >= mid)
                return true;

        }

        return have >= mid;
    };

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
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