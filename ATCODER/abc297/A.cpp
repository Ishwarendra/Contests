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
    
    int n, D;
    std::cin >> n >> D;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] <= D)
        {
            std::cout << a[i + 1];
            return 0;
        }
    }

    std::cout << -1;
    
    return 0;
}