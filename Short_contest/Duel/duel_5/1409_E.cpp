#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i];

    for (int i = 0; i < n; ++i)
    {
        int y;
        std::cin >> y;
    }

    std::sort(std::begin(x), std::end(x));
    std::vector<int> max(n);
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n and x[j] - x[i] <= k)
            j++;

        max[i] = j - i;
    }

    for (int i = n - 2; i >= 0; i--)
        max[i] = std::max(max[i], max[i + 1]);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int id = std::upper_bound(std::begin(x), std::end(x), x[i] + k) - std::begin(x);
        int cur_ans = id - i;

        if (id < n)
            cur_ans += max[id];

        ans = std::max(ans, cur_ans);
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