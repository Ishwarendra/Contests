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

    n *= 7;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n / 7; i++)
    {
        int sum = 0;
        for (int j = 0; j < 7; j++)
            sum += a[i * 7 + j];

        std::cout << sum << " ";
    }
    
    return 0;
}