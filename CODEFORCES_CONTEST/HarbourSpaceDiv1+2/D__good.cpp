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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '0')
                continue;

            ans++;
            print(i, j)
            a[i][j] ^= '0' ^ '1';
            for (int x = i + 1; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (x - i >= std::abs(y - j))
                        a[x][y] ^= '0' ^ '1';
                }
            }
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