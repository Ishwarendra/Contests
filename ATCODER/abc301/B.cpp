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

    for (int i = 1; i < n; i++)
    {   
        if (a[i - 1] > a[i]) for (int j = a[i - 1]; j > a[i]; j--)
            std::cout << j << " ";
        if (a[i - 1] < a[i]) for (int j = a[i - 1]; j < a[i]; j++)
            std::cout << j << " ";
    }

    std::cout << a.back();
    
    return 0;
}