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

    std::vector a(n, std::vector(m, 0));
    int i;
    int num = 0;
    for (i = 0; i <= std::min(n - 1, std::max(0, n - m + 1)); i++)
    {
        num = 0;
        for (int j = 0; j < m; j++)
            a[i][j] = num++;
    }  

    int st = 1;
    for (; i < n; i++)
    {
        num = st;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = num;
            num = (num + 1) % m;
        }
        st++;
    }

    std::set<int> mex;
    for (int j = 0; j < m; j++)
    {
        std::set<int> vis;
        for (int i = 0; i < n; i++)
            vis.emplace(a[i][j]);

        num = 0;
        while (vis.count(num))
            num++;

        mex.emplace(num);
    }

    int ans = 0;
    while (mex.count(ans))
        ans++;

    std::cout << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << " \n"[j == m - 1];
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