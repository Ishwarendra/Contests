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

    std::vector<int> pmin(n + 2), pmax(n + 2), max(n + 2), min(n + 2);
    pmax[0] = 1, max[0] = 1;

    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        char ch;
        std::cin >> ch;

        if (ch == '+')
        {
            int v, x;
            std::cin >> v >> x;
            v--;

            pmax[cur] = std::max(pmax[v] + x, x);
            pmin[cur] = std::min(pmin[v] + x, x);
            
            min[cur] = std::min({min[cur], min[v], x, pmin[cur]});
            max[cur] = std::max({max[cur], max[v], x, pmax[cur]});
            cur++;
        }
        else
        {
            int u, v, k;
            std::cin >> u >> v >> k;
            u--, v--;

            if (min[v] <= k and k <= max[v])
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
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