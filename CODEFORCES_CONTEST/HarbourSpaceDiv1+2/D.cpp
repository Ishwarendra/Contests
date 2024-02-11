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
        {
            char ch;
            std::cin >> ch;
            a[i][j] = ch - '0';
        }
    }

    std::vector b(n, 0), c(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::vector nb(n, 0), nc(n, 0), d(n, 0);

        d[0] = b[0] ^ c[0];
        for (int j = 1; j < n; j++)
            d[j] = d[j - 1] ^ b[j] ^ c[j];

        for (int j = 0; j < n; j++)
        {
            a[i][j] ^= d[j];
            ans += a[i][j];

            if (a[i][j])
            {
                nb[std::max(0, j - 1)] ^= 1;
                if (j + 2 < n)
                    nc[j + 2] ^= 1;
            }
        }

        for (int j = 0; j < n; j++)
        {
            nb[std::max(0, j - 1)] ^= b[j];
            if (j + 2 < n)
                nc[j + 2] ^= c[j];
        }

        std::swap(b, nb);
        std::swap(c, nc);
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