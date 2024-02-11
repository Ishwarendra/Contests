#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> c(n);
    std::vector a(n, std::vector<int>());
    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> c[i] >> len;
        a[i].assign(len, 0);

        for (int j = 0; j < len; j++)
            std::cin >> a[i][j];
    }

    std::vector<l64> dp(m + 1);
    for (int s = 0; s <= m; s++)
    {
        for (int i = 0; i < n; i++)
        {
            l64 add = 0;
            int cnt = 0, len = std::size(a[i]);
            for (auto point : a[i])
            {
                if (point == 0)
                    cnt++;
                else
                    add += dp[std::max(0, s - point)] / len;
            }
        }
    }
    
    return 0;
}