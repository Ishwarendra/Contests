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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (2LL * k >= a[i])
        {
            k = std::max(k, a[i]);
            continue;
        }

        while (2LL * k < a[i])
        {
            count++;
            k *= 2;
        }

        k = std::max(k, a[i]);
    }

    std::cout << count;
    
    return 0;
}