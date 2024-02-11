#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::vector<std::pair<int, int>> pos;
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        for (int j = 0; j < std::size(a[i]); ++j)
        {
            if (a[i][j] == '*')
                pos.emplace_back(i, j);
        }
    }

    auto [x1, y1] = pos[0];
    auto [x2, y2] = pos[1];

    if (x1 == x2)
    {
        if (x1 > 0)
            a[x1 - 1][y1] = a[x2 - 1][y2] = '*';
        else
            a[x1 + 1][y1] = a[x2 + 1][y2] = '*';
    }
    else if (y1 == y2)
    {
        if (y1 > 0)
            a[x1][y1 - 1] = a[x2][y2 - 1] = '*';
        else
            a[x1][y1 + 1] = a[x2][y2 + 1] = '*';
    }
    else
        a[x1][y2] = a[x2][y1] = '*';

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << "\n";
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