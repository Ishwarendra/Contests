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
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> p(n);
    for (int i = 1; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
    }

    for (int j = 0; j < 100; j++)
    {   
        for (int i = 1; i < n; i++)
            a[p[i]] += a[i];
    }

    std::cout << (a[0] < 0 ? '-' : a[0] == 0 ? '0' : '+');

    return 0;
}