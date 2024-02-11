#include <bits/stdc++.h>

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

    std::vector<std::multiset<int>> nums(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            std::cin >> x;

            nums[j].emplace(x);
        }
    }

    int left = 1, right = 1e9;
    int ans = 0;

    auto good = [&](int k, std::vector<std::multiset<int>> a)
    {
        for (int i = 0; i < m; i++)
        {
            while (std::size(a[i]) > 1)
            {
                int cur_num = *std::begin(a[i]);
                a[i].erase(std::begin(a[i]));

                auto it1 = std::lower_bound(std::begin(a[i]), std::end(a[i]), cur_num + k);

                if (it1 == std::end(a[i]))
                    return false;

                a[i].erase(it1);
            }
        }

        return true;
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (good(mid, nums))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans;

    return 0;
}