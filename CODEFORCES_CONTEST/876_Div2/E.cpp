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

    auto query = [&](auto s)
    {
        std::cout << s << std::endl;
    };

    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    constexpr int N = 9e4 + 1;
    std::bitset<N> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        dp |= (dp << a[i]);

    int sum = std::accumulate(std::begin(a), std::end(a), 0);
    if (sum % 2 or dp[sum / 2] == 0)
    {
        query("First");
        int can = 1;
        while (can)
        {
            can = 0;
            int max_id = std::max_element(std::begin(a), std::end(a)) - std::begin(a);
            query(max_id + 1);
            int j;
            std::cin >> j;
            j--;

            if (j >= 0)
            {
                a[max_id] -= a[j];
                a[j] = 0;
                can = 1;
            }
        }
    }
    else
    {
        std::vector<int> subset(n);
        std::vector dp1(n + 1, std::array<int, N>{});
        dp1[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int s = 0; s < N; s++)
            {
                dp1[i][s] |= dp1[i - 1][s];
                if (s + a[i - 1] < N and dp1[i - 1][s])
                {
                    dp1[i][s + a[i - 1]] = 1;
                }
            }
        }
        
        sum /= 2;
        for (int i = n; i > 0; i--)
        {
            if (sum - a[i - 1] >= 0 and dp1[i][sum] and dp1[i - 1][sum - a[i - 1]])
            {
                subset[i - 1] = 1;
                sum -= a[i - 1];
            }
        }

        assert(sum == 0);
        query("Second");
        while (true)
        {
            int j;
            std::cin >> j;
            j--;

            if (j < 0)
                break;

            for (int i = 0; i < n; i++)
            {
                if (subset[i] == subset[j] or a[i] == 0)
                    continue;

                query(i + 1);
                int sub = std::min(a[i], a[j]);
                a[i] -= sub;
                a[j] -= sub;
                break;
            }
        }
    }

    return 0;
}