#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto pref = [&](char ch)
    {
        std::vector pr(n, std::vector(m, 0));
        auto pc = pr;

        for (int i = 0; i < n; i++)
        {
            pr[i][0] = a[i][0] == ch;
            for (int j = 1; j < m; j++)
                pr[i][j] = pr[i][j - 1] + (a[i][j] == ch); 
        }

        for (int j = 0; j < m; j++)
        {
            pc[0][j] = a[0][j] == ch;
            for (int i = 1; i < n; i++)
                pc[i][j] = pc[i - 1][j] + (a[i][j] == ch);
        }

        return std::pair {pr, pc};
    };

    auto [pro, pco] = pref('o');
    auto [prx, pcx] = pref('x');

    int ans = inf;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j + k - 1 < m; j++)
        {
            if (prx[i][j + k - 1] - (j ? prx[i][j - 1] : 0) != 0)
                continue;

            int o = pro[i][j + k - 1] - (j ? pro[i][j - 1] : 0);
            ans = std::min(ans, k - o);
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i + k - 1 < n; i++)
        {
            if (pcx[i + k - 1][j] - (i ? pcx[i - 1][j] : 0) != 0)
                continue;

            int o = pco[i + k - 1][j] - (i ? pco[i - 1][j] : 0);
            ans = std::min(ans, k - o);
        }
    }

    std::cout << (ans == inf ? -1 : ans);
    
    return 0;
}