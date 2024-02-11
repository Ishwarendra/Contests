#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i].first;
    for (int i = 0; i < n; i++)
        std::cin >> c[i].second;

    std::sort(std::begin(c), std::end(c));

    i64 ans = 0;
    for (int ai = 1; ai * ai <= 2 * n; ai++)
    {
        std::vector<int> freq(n + 1, 0);
        for (auto [a, b] : c)
        {
            int bi = ai * a - b;
            if (bi >= 1 and bi <= n)
                ans += freq[bi];

            if (a == ai)
                freq[b]++;
        }
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