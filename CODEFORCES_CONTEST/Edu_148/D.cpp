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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    auto b = a;
    while (q--)
    {
        int k;
        std::cin >> k;

        auto good = [&](int mid)
        {
            std::vector<int> need(n);
            int sub = 0;
            for (int i = 0; i < n; i++)
            {
                if (i < k and (sub < std::min(n, k) - 1 or k < n or
                        (sub == std::min(n, k) - 1 and k % 2 == n % 2)))
                {
                    need[i] = a[i] + k - sub - mid;
                    sub++;
                }
                else
                    need[i] = a[i] - mid;

                if (need[i] < 0)
                    return false;
            }   
            int d = k - sub;
            int sub2 = d / 2;

            for (int i = 0; i < n; i++)
                sub2 -= std::min(sub2, need[i]);

            return sub2 == 0;
        };

        std::sort(std::begin(a), std::end(a));
        int left = -1e9, right = 2e9;
        int ans = 0;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (good(mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        std::cout << ans << " \n"[q == 0];

        a = b;
    }
    
    return 0;
}