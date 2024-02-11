#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 2e5 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] += p[i - 1] + a[i];

    i64 ans = 0;
    std::bitset<N> dp{};
    std::set<int> rem;
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        dp |= (dp << a[i]);
        if (dp[i])
        {
            ans = std::max(ans, p[i] - i);
            dp[i] = 0;
        }
    }

    for (int i = n; i < 2 * n; i++)
    {
        if (dp[i])
            ans = std::max(ans, p.back() - i);
    }

    std::cout << ans;

    return 0;
}