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
    
    int n, m;
    i64 d;
    std::cin >> n >> m >> d;

    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    i64 ans = -1;
    std::sort(std::begin(b), std::end(b));

    for (int i = 0; i < n; i++)
    {
        auto it = std::upper_bound(std::begin(b), std::end(b), a[i] + d) - std::begin(b) - 1;
        if (it < 0)
            continue;
        if (std::abs(a[i] - b[it]) <= d)
            ans = std::max(ans, a[i] + b[it]);
    }
    
    std::cout << ans;

    return 0;
}