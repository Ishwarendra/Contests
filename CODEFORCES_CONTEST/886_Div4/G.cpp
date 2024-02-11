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

    std::map<int, int> sum, diff, xc, yc;
    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)  
    {
        int x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
        diff[x - y]++;
        sum[x + y]++;
        xc[x]++;
        yc[y]++;
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += diff[a[i][0] - a[i][1]];
        ans += sum[a[i][0] + a[i][1]];
        ans -= 2;

        ans += xc[a[i][0]] + yc[a[i][1]] - 2;
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