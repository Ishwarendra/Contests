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

    std::vector a(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    std::vector<int> b(n, (1 << 30) - 1);
    for (int pos = 0; pos < 30; pos++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (!getBit(a[i][j], pos))
                {
                    if (getBit(b[i], pos))
                        b[i] ^= 1 << pos;
                    if (getBit(b[j], pos))
                        b[j] ^= 1 << pos;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j and a[i][j] != (b[i] | b[j]))
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
        std::cout << b[i] << " \n"[i == n - 1];
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