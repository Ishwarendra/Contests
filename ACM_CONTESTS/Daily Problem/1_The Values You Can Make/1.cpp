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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    // dp[i][s][y] => Using subset of first i element, can we make sum exactly s
    //                and using some subset of it can we make sum exactly y?
    std::vector dp(k + 1, std::vector(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int s = k; s >= 0; s--)
        {
            for (int y = s; y >= 0; y--)
            {
                if (s + a[i] > k || y + a[i] > k)
                    continue;
                if (!dp[s][y])
                    continue;

                dp[s + a[i]][y] = dp[s + a[i]][y + a[i]] = 1;
            }
        }
    }

    std::vector<int> ans;
    for (int i = 0; i <= k; i++)
    {
        if (dp[k][i])
            ans.emplace_back(i);
    }

    int sz = std::size(ans);
    std::cout << sz << "\n";
    for (int i = 0; i < sz; i++)
        std::cout << ans[i] << " \n"[i == sz - 1];

    return 0;
}