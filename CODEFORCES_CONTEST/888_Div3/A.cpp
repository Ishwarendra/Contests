#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k, h;
    std::cin >> n >> m >> k >> h;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;

        int d = std::abs(a - h);
        if (d % k == 0 and d / k < m and d != 0)
            ans++;
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