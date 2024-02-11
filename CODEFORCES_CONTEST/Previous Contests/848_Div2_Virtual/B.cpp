#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> a(n), pos(n), b(m);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        pos[--a[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
        b[i]--;
    }

    int ans = 1e9;
    for (int i = 0; i < m - 1; i++)
    {
        bool bad = (pos[b[i]] < pos[b[i + 1]]) and (pos[b[i + 1]] <= pos[b[i]] + d); 
        if (!bad)
        {
            std::cout << "0\n";
            return;
        }

        int diff = pos[b[i + 1]] - pos[b[i]];
        ans = std::min(ans, diff);

        int need = d - diff + 1;
        if (d < n - 1)
            ans = std::min(ans, need);
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