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

    std::vector a(m, std::vector(n, 0));
    i64 ans = 0;
    for (int j = 0; j < n; j++)  
    {
        for (int i = 0; i < m; i++)
            std::cin >> a[i][j];
    }

    for (auto &p : a)
    {
        std::sort(std::begin(p), std::end(p));
        for (int i = 0; i < n; i++)
            ans += 1LL * p[i] * i - 1LL * (n - i - 1) * p[i];
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