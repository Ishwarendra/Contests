#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];


    std::sort(std::begin(a), std::end(a));
    
    for (int i = 0; i < n; i++)
    {
        if (a[n - 1] % a[i])
        {
            std::cout << n << "\n";
            return;
        }
    }

    auto check = [&](int d)
    {
        int len = 0;
        int lcm = 1;
        for (auto x : a)
        {
            if (d % x == 0)
            {
                lcm = std::lcm(lcm, x);
                len++;
            }
        }
        
        return lcm == d ? len : 0;
    };

    int ans = 0;
    for (int i = 1; 1LL * i * i <= a[n - 1]; i++)
    {
        if (a[n - 1] % i)
            continue;

        for (int d : { i, a[n - 1] / i })
        {
            if (!std::binary_search(std::begin(a), std::end(a), d))
                ans = std::max(ans, check(d));
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