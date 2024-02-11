#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void chkmin(auto &a, auto b)
{
    if (a > b)
        a = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    i64 need = 0, have = 0;
    std::vector<std::pair<int, int>> a;

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;

        need += z;
        if (x > y)
            have += z;
        else
        {
            int k = (y - x) / 2 + 1;
            a.emplace_back(k, z);
        }
    }

    need = (need + 1) / 2 - have;
    if (need <= 0)
    {
        std::cout << 0;
        return 0;
    }
    print(a, need)
    n = std::size(a);
    std::vector dp(need + 1, inf);

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector ndp(need + 1, inf);
        for (int s = 0; s <= need; s++)
        {
            if (dp[s] == inf)
                continue;

            chkmin(ndp[std::min<int>(need, s + a[i].second)], dp[s] + a[i].first);
            chkmin(ndp[s], dp[s]);
        }

        std::swap(dp, ndp);
    }

    std::cout << dp[need];
    
    return 0;
}