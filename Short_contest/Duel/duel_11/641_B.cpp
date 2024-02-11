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

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector a(n, std::vector(m, 0));
    std::vector par(n, std::vector(m, std::pair<int, int>()));
    std::map<std::pair<int, int>, int> val;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            par[i][j] = {i, j};
    }

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int r;
            std::cin >> r;
            r--;

            auto first = par[r][0];
            for (int i = 0; i < m - 1; i++)
                par[r][i] = par[r][i + 1];
            par[r].back() = first;
        }
        else if (t == 2)
        {
            int c;
            std::cin >> c;
            c--;

            auto first = par[0][c];
            for (int i = 0; i < n - 1; i++)
                par[i][c] = par[i + 1][c];
            
            par[n - 1][c] = first;
        }
        else
        {
            int r, c, x;
            std::cin >> r >> c >> x;
            r--, c--;

            std::tie(r, c) = par[r][c];
            a[r][c] = x;
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << " \n"[j == m - 1];
    }
    return 0;
}