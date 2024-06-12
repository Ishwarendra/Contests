#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    auto b = a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> b[i][j];
    }

    auto colSwap = [&](auto &b, int x, int y)
    {
        std::vector<int> c(n);
        for (int i = 0; i < n; i++)  
            c[i] = b[i][x];
        
        for (int i = 0; i < n; i++)
        {
            b[i][x] = b[i][y];
            b[i][y] = c[i];
        }
    };

    auto get = [&](auto &b)
    {
        std::vector res(n, std::vector(m, 0));
        
        int onex = 0, oney = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (b[i][j] == 1)
                    onex = i, oney = j;
            }
        }
        
        std::swap(b[0], b[onex]);
        colSwap(b, 0, oney);
        auto c = b[0];

        std::map<int, int> pos;
        for (int i = 0; i < m; i++)
            pos[b[0][i]] = i;
        
        std::sort(std::begin(c), std::end(c));
        std::vector<int> id(m);
        
        for (int i = 0; i < m; i++)
            id[i] = pos[c[i]];

        for (int i = 0; i < n; i++)
        {
            auto t = b[i];
            int idx = 0; 
            for (int j : id)
                res[i][idx++] = t[j];
        }

        std::sort(std::begin(res), std::end(res));
        return res;
    };
    
    std::cout << (get(a) == get(b) ? "YES\n" : "NO\n");
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