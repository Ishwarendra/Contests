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

    std::array<int, 2> st{n, m}, en{-1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                st[0] = std::min(st[0], i);
                st[1] = std::min(st[1], j);
                en[0] = std::max(en[0], i);
                en[1] = std::max(en[1], j);
            }
        }
    }

    for (int i = st[0]; i <= en[0]; i++)
    {
        for (int j = st[1]; j <= en[1]; j++)
        {
            if (a[i][j] == '.')
            {
                std::cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    return 0;
}