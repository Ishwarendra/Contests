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

    std::map<std::pair<int, int>, i64> dp;
    std::function<i64(int, int)> f = [&](int id, int u) -> i64
    {
        if (id > u)
            return 0LL;

        if (dp.contains({id, u}))
            return dp[{id, u}];

        auto &ans = dp[{id, u}] = 0;
        if (u == n - 1)
            ans = a[id] + f(id + 1, u);
        else
            ans = std::max(a[id] + f(id + 1, u), f(id + 1, std::min(n - 1, u + a[id])));
        return ans;
    };

    std::cout << f(0, 0);

    return 0;
}