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
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int left = 1, right = n;
    int ans = 1;

    auto good = [&](int mid)
    {
        int need = 1;
        int add = 1;
        for (int i = 0; i < n; i++)
        {
            if (need == mid + 1)
                add = -1, need -= 2;

            if (a[i] >= need)
                need += add;
            else
                add = 1, need = a[i] + 1;

            if (need <= 0)
                return true;
        }

        return need <= 0;
    };

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans;
    
    return 0;
}