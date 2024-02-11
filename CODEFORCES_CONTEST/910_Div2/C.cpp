#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    int d = std::abs(n - 1) + std::abs(m - 1);
    if (d % 2 != k % 2 or k < d)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        std::vector a(n - 1, std::string(m, 'R'));
        std::vector b(n, std::string(m - 1, 'R'));
        char ch = 'R';

        b[0][0] = b[1][0] = 'B';
        a[0][2] = 'B';

        for (int i = 0; i < n - 1; i++)
            a[i][0] = ch, ch = ch ^ 'R' ^ 'B';

        ch = 'B';
        for (int i = (n % 2); i < m - 1; i++)
            b[n - 1][i] = ch, ch = ch ^ 'R' ^ 'B';

        if (b.back().back() == 'B')
            a.back()[m - 1] = a.back()[m - 2] = 'B';
        else
            b[n - 2].back() = 'B';        

        for (auto &x : {b, a})
        {
            for (auto s : x)
            {
                for (auto ch : s)
                    std::cout << ch << " ";
                std::cout << "\n";
            }
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