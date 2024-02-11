#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n * m);
    for (int i = 0; i < n * m; i++)  
        std::cin >> a[i];

    if (n < m)
        std::swap(n, m);

    std::sort(std::begin(a), std::end(a));
    int min1 = a[0], min2 = a[1], max1 = a[n * m - 1], max2 = a[n * m - 2];

    int total = n * m;
    i64 ans = (n - 1LL) * (max1 - min1) + (m - 1LL) * (max1 - min2) + (total - n - m + 1LL) * (max1 - min1);
    ans = std::max(ans, (n - 1LL) * (max1 - min1) + (m - 1LL) * (max2 - min1) + (total - n - m + 1LL) * (max1 - min1));

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