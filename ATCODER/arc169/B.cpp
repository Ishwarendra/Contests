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
    i64 s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];

    auto get = [&](int id)
    {
        auto good = [&](int mid)
        {
            return p[id] - (mid ? p[mid - 1] : 0) <= s;
        };

        int left = 0, right = id;
        int ans = id;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (good(mid))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    };

    std::vector<i64> dp(n);
    dp[0] = 1;
    for (int r = 1; r < n; r++)
    {
        int l = get(r);
        dp[r] = (r - l + 1);
        if (l)
            dp[r] += dp[l - 1] + l;
    }

    std::cout << std::accumulate(std::begin(dp), std::end(dp), 0LL);

    return 0;
}