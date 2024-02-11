#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, h;
    std::cin >> n >> m >> h;

    std::vector a(n, std::vector(m, 0LL));
    std::vector rank(n, std::tuple<int, i64, int>());
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

        std::sort(std::begin(a[i]), std::end(a[i]));
        std::vector<i64> p(m);
        p[0] = a[i][0];
        for (int j = 1; j < m; j++)
            p[j] += p[j - 1] + a[i][j];

        int j = 0;
        int tot = 0;
        i64 penalty = 0;
        while (j < m and tot + a[i][j] <= h)
        {
            tot += a[i][j];
            penalty += p[j];
            j++;
        }

        rank[i] = {j, -penalty, -i};
    }

    std::sort(std::rbegin(rank), std::rend(rank));
    print(rank)
    int ans = 1;
    for (auto &[_, __, pos] : rank)
    {
        if (std::abs(pos) == 0)
        {
            std::cout << ans << "\n";
            return;
        }

        ans++;
    }
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