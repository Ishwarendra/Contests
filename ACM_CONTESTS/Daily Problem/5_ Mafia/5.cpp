#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 left = *std::max_element(std::begin(a), std::end(a));
    i64 right = 1e15;
    i64 ans = 0;

    auto good = [&](i64 mid)
    {
        i64 have = 0;
        for (int i = 0; i < n; i++)
        {
            have += mid - a[i];
            if (have >= mid)
                return true;
        }

        return have >= mid;
    };

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}