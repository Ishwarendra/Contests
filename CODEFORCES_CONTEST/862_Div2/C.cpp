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

    std::vector<i64> k(n);
    for (int i = 0; i < n; i++)
        std::cin >> k[i];

    std::sort(std::begin(k), std::end(k));
    k.erase(std::unique(std::begin(k), std::end(k)), std::end(k));
    n = std::size(k);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (4LL * a * c < 0)
            std::cout << "NO\n";
        else
        {
            i64 x = std::sqrt(4LL * a * c);
            int id = std::lower_bound(std::begin(k), std::end(k), b - x) - std::begin(k);

            bool done = false;
            for (int i = std::max<int>(0, id - 100); i < std::min<int>(id + 100, n); i++)
            {
                if (1LL * (b - k[i]) * (b - k[i]) < 4LL * a * c)
                {
                    std::cout << "YES\n" << k[i] << "\n";
                    done = true;
                    break;
                }
            }

            if (!done)
                std::cout << "NO\n";
        }
    }
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