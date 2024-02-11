#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    const int n = 10;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 'X')
                continue;

            int add = 0;
            for (int x = 0; x < 5; x++)
            {
                if (add > 0)
                    break;

                for (int id : {i, j})
                {
                    if (id == x or id == n - 1 - x)
                    {
                        add = std::min(x, n - 1 - x) + 1;
                        break;
                    }
                }
            }

            ans += add;
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