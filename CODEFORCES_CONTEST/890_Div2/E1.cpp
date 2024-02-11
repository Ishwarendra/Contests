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

    std::vector<int> adj[n], dep(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;

        adj[p - 1].emplace_back(i);
        dep[i] = dep[p - 1] + 1;
    }

    std::vector<int> a(n), cnt(n, 1);
    std::function<void(int)> getCnt = [&](int u)
    {
        for (int v : adj[u])
        {
            getCnt(v);
            cnt[u] += cnt[v];
        }
    }; getCnt(0);

    auto equalSubset = [&](std::vector<int> &nums)
    {
        int sz = std::size(nums);
        int total = std::accumulate(std::begin(nums), std::end(nums), 0);

        std::vector dp(sz + 1, std::vector(total + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= sz; i++)
        {   
            for (int sum = 0; sum <= total; sum++)
            {
                dp[i][sum] |= dp[i - 1][sum];
                if (sum - nums[i - 1] >= 0)
                    dp[i][sum] |= dp[i - 1][sum - nums[i - 1]];
            }
        }

        std::vector<int> subset(sz);
        int need = 0;
        for (int sum = 0; sum <= total; sum++)
        {
            if (!dp.back()[sum])
                continue;

            if (std::abs(2 * need - total) > std::abs(2 * sum - total))
                need = sum;
        }
        
        return need * (total - need);
    };

    int ans = 0;    
    for (int u = 0; u < n; u++)
    {
        std::vector<int> nums;
        for (int v : adj[u])
            nums.emplace_back(cnt[v]);

        ans += equalSubset(nums);
    }
    
    std::cout << ans;

    return 0;
}