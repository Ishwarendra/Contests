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

    if (n <= 2)
    {
        std::cout << (n == 1 ? "1\n" : "-1\n");
        return;
    }

    std::vector a(n, std::vector(n, 0));
    a[0][0] = 1;
    a[1][2] = 1;
    a[2][0] = a[2][1] = a[2][2] = 1;

    auto get = [&](int x)
    {
        return (x * x + 1) / 2 - ((x - 1) * (x - 1) + 1) / 2;
    };

    for (int i = 3; i < n; i++)
    {
        int ones = get(i + 1);
        for (int j = 1; j < std::min(ones + 1, i + 1); j++)
            a[i][j] = 1;

        ones -= std::min(ones, i);
        int r = i - 1, c = i;
        while (ones and r >= 0)
        {
            a[r][c] = 1;
            ones--;
            r--;
        }
    }

    int odd = 1, even = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto &x = a[i][j] ? odd : even;
            std::cout << x << " \n"[j == n - 1];
            x += 2;
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