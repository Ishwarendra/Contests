#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void read(std::vector<std::vector<int>> &a)
{
    for (auto &row : a)
    {
        for (auto &x : row)
            std::cin >> x;
    }
}

auto swap(auto &p, int i, int j)
{
    std::vector<int> col;
    for (int k = 0; k < std::size(p[0]); k++)
        col.emplace_back(p[i][k]);

    for (int k = 0; k < std::size(p[0]); k++)
    {
        p[i][k] = p[j][k];
        p[j][k] = col[k];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    std::vector b(n, std::vector(m, 0));

    read(a); read(b);
    int ans = -1;

    std::vector<int> row(n), col(m);
    std::iota(std::begin(row), std::end(row), 0);

    do
    {
        std::iota(std::begin(col), std::end(col), 0);
        do
        {
            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    ok &= a[row[i]][col[j]] == b[i][j];
            }

            if (!ok)
                continue;

            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                    cur += row[i] > row[j];
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = i + 1; j < m; j++)
                    cur += col[i] > col[j];
            }

            if (ans == -1 || cur < ans)
                ans = cur;

        } while (std::next_permutation(std::begin(col), std::end(col)));

    } while (std::next_permutation(std::begin(row), std::end(row)));
    
    std::cout << ans;

    return 0;
}