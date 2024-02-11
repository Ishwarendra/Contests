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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<i64> suff(n + 1);
    suff[n - 1] = std::max(0, a.back());

    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + std::max(0, a[i]);

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        i64 cur = a[i] * (i % 2 == 0);
        cur += suff[i + 1];
        ans = std::max(ans, cur);
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