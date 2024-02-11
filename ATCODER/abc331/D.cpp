#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector p(n + 1, std::vector(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            std::cin >> ch;
            p[i][j] = ch == 'B';
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
            p[i][j] = p[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    }

    auto get = [&](auto &&self, int a, int b) -> i64
    {
        if (a > n)
            return (a / n) * self(self, n, b) + self(self, a % n, b);
        if (b > n)
            return (b / n) * self(self, a, n) + self(self, a, b % n);

        return p[a][b];
    };

    while (q--)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        c++, d++;
        std::cout << get(get, a, b) + get(get, c, d) - get(get, a, d) - get(get, c, b) << "\n";
    }

    return 0;
}