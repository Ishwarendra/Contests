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

    for (int i = 0, base = 1 << 20; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            a[i][j] = (i * base) ^ j;
    }

    std::cout << n * m << "\n";
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

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}