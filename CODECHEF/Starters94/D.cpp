#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int getBit(int x, int pos) { return x >> pos & 1; };

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    std::array<int, 30> tot{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
            for (int pos = 0; pos < 30; pos++)
                tot[pos] += getBit(a[i][j], pos);
        }
    }

    std::vector dpR(n, std::array<int, 30>());
    std::vector dpC(m, std::array<int, 30>());

    for (int i = 0; i < n; i++)
    {
        auto &x = dpR[i];
        for (int j = 0; j < m; j++)
        {
            for (int pos = 0; pos < 30; pos++)
                x[pos] += getBit(a[i][j], pos);
        }
    }

    for (int j = 0; j < m; j++)
    {
        auto &x = dpC[j];
        for (int i = 0; i < n; i++)
        {
            for (int pos = 0; pos < 30; pos++)
                x[pos] += getBit(a[i][j], pos);
        }
    }

    auto get = [&](std::array<int, 30> &x)
    {
        i64 ans = 0;
        for (int i = 0; i < 30; i++)
            ans += (1LL << i) * x[i];
        return ans;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::array<int, 30> cur{};
            for (int pos = 0; pos < 30; pos++)
            {
                int total = tot[pos];
                int row = dpR[i][pos];
                int col = dpC[j][pos];

                if (getBit(a[i][j], pos))
                {
                    total = n * m - total;
                    row = n - row;
                    col = m - col;
                }

                cur[pos] = total - row - col;
            }

            ans = std::max(ans, get(cur));
        }
    }

    std::cout << ans << "\n";
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