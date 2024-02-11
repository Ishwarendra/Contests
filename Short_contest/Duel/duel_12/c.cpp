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

    auto b = a;
    std::sort(std::begin(b), std::end(b));
    int same = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != a[0] % 2)
            same = 0;
    }

    if (!same)
        std::swap(a, b);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
    
    return 0;
}