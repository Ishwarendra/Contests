#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n = 8;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        int cntR = 0, cntB = 0;
        for (int j = 0; j < n; j++)
        {
            cntR += a[i][j] == 'R';
            cntB += a[j][i] == 'B';
        }

        if (cntR == 8)
        {
            std::cout << "R\n";
            return;
        }

        if (cntB == 8)
        {
            std::cout << "B\n";
            return;
        }
    }

    std::cout << "baka :(\n";
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