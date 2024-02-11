#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> pos(k);
    for (int i = 0; i < k; i++)
        pos[i].emplace_back(-1);

    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        pos[c - 1].emplace_back(i);
    }

    for (int i = 0; i < k; i++)
        pos[i].emplace_back(n);

    auto good = [&](int mid)
    {
        for (int i = 0; i < k; i++)
        {
            int cnt = 0;
            for (int j = 1; j < std::size(pos[i]); j++)
            {
                int d = pos[i][j] - pos[i][j - 1] - 1;
                cnt += d / (mid + 1);
            }

            if (cnt < 2)
                return true;
        }

        return false;
    };

    int left = 0, right = n;
    int ans = -1;

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