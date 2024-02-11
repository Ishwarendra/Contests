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

    std::vector<i64> sum(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> sum[i];
    std::sort(std::begin(sum), std::end(sum));

    for (int i = 1; i < n; i++)
        sum[i] += sum[i - 1];

    i64 ans = 0;
    for (int x = 0; x <= k; x++)
    {
        int y = k - x;
        print(x, y, sum[n - y - 1] - (2 * x - 1 < 0 ? 0LL : sum[2 * x - 1]))
        ans = std::max(ans, sum[n - y - 1] - (2 * x - 1 < 0 ? 0LL : sum[2 * x - 1]));
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}