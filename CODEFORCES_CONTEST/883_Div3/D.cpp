#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;

void solve()
{
    int n, d, h;
    std::cin >> n >> d >> h;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    l64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 0.5L * d * h;
        if (i + 1 < n and a[i + 1] - a[i] < h)
        {
            int nh = h - (a[i + 1] - a[i]);
            l64 nd = 1.0L * nh * d / h;
            ans -= 0.5L * nh * nd;
        }
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(12);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}