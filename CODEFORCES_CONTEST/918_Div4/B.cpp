#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    const int n = 3;
    std::vector a(n, std::string(n, '1'));
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    char ans = 'A' ^ 'B' ^ 'C';
    for (int i = 0; i < n; i++)
    {
        int skip = 1;
        for (int j = 0; j < n; j++)
            skip &= a[i][j] != '?';

        if (skip)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != '?')
                ans ^= a[i][j];
        }

        std::cout << ans << "\n";
        return;
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