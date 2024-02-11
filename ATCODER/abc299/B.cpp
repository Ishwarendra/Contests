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
    
    int n, t;
    std::cin >> n >> t;

    std::vector a(n, std::array {0, 0, 0});
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i][0];
        a[i][2] = i + 1;
    }

    int color = a[0][0];
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == t)
            color = t;
    }

    for (int i = 0; i < n; i++)
        a[i][0] = a[i][0] == color;

    for (int i = 0; i < n; i++)
        std::cin >> a[i][1];

    std::sort(std::rbegin(a), std::rend(a));

    std::cout << a[0][2];
    
    return 0;
}