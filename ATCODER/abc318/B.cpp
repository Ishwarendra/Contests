#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector a(N + 1, std::vector(N + 1, 0));
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2;
        std::cin >> x1 >> x2 >> y1 >> y2;

        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
                a[y][x] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
            ans += a[i][j];
    }

    std::cout << ans;

    return 0;
}