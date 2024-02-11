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
    std::cin >> n >> m;

    std::vector<std::string> col(n + 1), d(m + 1);
    std::map<std::string, int> price;

    for (int i = 1; i <= n; i++)
        std::cin >> col[i];

    for (int i = 1; i <= m; i++)
        std::cin >> d[i];
    for (int i = 0; i <= m; i++)
    {
        int x;
        std::cin >> x;
        price[d[i]] = x;
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (price.count(col[i]))
            ans += price[col[i]];
        else
            ans += price[""];
    }

    std::cout << ans;
    
    return 0;
}