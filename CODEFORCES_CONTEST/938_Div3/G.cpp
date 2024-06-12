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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    std::vector s(n, std::vector(m, std::set<int, std::greater<>>()));
    s[0][0].emplace(a[0][0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n)
            {
                for (auto &g : s[i][j])
                    s[i + 1][j].emplace(std::gcd(a[i + 1][j], g));
            }

            if (j + 1 < m)
            {
                for (auto &g : s[i][j])
                    s[i][j + 1].emplace(std::gcd(a[i][j + 1], g));
            }
        }
    }

    std::cout << *std::begin(s[n - 1][m - 1]) << "\n";
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