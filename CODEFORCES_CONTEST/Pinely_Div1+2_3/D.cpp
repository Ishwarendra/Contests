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
    i64 k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] -= k;
    }

    if (std::size(std::set(std::begin(a), std::end(a))) == 1)
    {
        std::cout << "0\n";
        return;
    }

    int all_neg = 1;
    for (int i = 0; i < n; i++)
        all_neg &= a[i] < 0;

    if (all_neg)
    {
        for (int i = 0; i < n; i++)
            a[i] = std::abs(a[i]);
    }

    i64 gcd = std::accumulate(std::begin(a), std::end(a), 0LL);
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            std::cout << "-1\n";
            return;
        }

        gcd = std::gcd(gcd, a[i]);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] / gcd - 1;
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