#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    constexpr int n = 8;
    std::vector<std::string> a(n);
    int x = -1, y = -1;

    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != '.' and x == -1)
                x = i, y = j;
        }
    }

    while (x < n and a[x][y] != '.')
    {
        std::cout << a[x][y];
        x++;
    }

    std::cout << "\n";
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