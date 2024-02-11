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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto change = [&](int x, int y, int d)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '#' and std::abs(i - x) + std::abs(j - y) <= d)
                    a[i][j] = '.';
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ('1' <= a[i][j] and a[i][j] <= '9')
            {
                int num = a[i][j] - '0';
                change(i, j, num);
                a[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\n";
    
    return 0;
}