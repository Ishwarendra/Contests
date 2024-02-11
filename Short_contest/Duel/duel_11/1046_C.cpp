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
    
    int n, d;
    std::cin >> n >> d;
    d--;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int left = 0, right = n - 1;
    int ans = -1;

    auto good = [&](int mid)
    {
        int max = a[d] + b.front();
        for (int i = mid, j = n - 1; i < n; i++)
        {
            if (i != d)
            {
                if (a[i] + b[j] > max)
                    return false;
                j--;
            }
        }

        return true;
    };

    while (left <= right)
    {
        int mid = left + right >> 1;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans + 1;
    
    return 0;
}