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

    std::vector<std::vector<int>> adj(m);
    std::vector<int> count(n + 1), ans(m);
    for (int i = 0; i < m; i++)  
    {
        int len;
        std::cin >> len;

        adj[i].resize(len);
        for (int j = 0; j < len; j++)
            std::cin >> adj[i][j];

        std::sort(std::begin(adj[i]), std::end(adj[i]));
    }

    for (int i = 0; i < m; i++)
    {
        ans[i] = adj[i][0];
        count[ans[i]]++;
    }

    for (int p = 0; p < n + 1; p++)
    {
        if (count[p] > (m + 1) / 2) // should be 1 or 0
        {
            for (int i = 0; i < m; i++)
            {
                int len = std::size(adj[i]);
                if (ans[i] == p)
                {
                    for (int j = 1; j < len; j++)
                    {
                        int p2 = adj[i][j];
                        if (count[p2] < (m + 1) / 2)
                        {
                            count[p2]++;
                            count[p]--;
                            ans[i] = p2;
                            break;
                        }
                    }
                }

                if (count[p] <= (m + 1) / 2)
                    break;
            }

        }
    }

    for (int p = 1; p <= n; p++)
    {
        if (count[p] > (m + 1) / 2)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < m; i++)
        std::cout << ans[i] << " \n"[i == m - 1];
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