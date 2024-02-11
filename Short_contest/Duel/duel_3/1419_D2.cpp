#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
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
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    if (n < 3)
    {
        std::cout << "0\n";
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
        return 0;
    }

    std::sort(std::begin(a), std::end(a));
    std::vector<int> b(n);

    int i = 1, j = 0;
    while (i < n)
        b[i] = a[j], i += 2, j++;

    i = 0;
    while (i < n)
        b[i] = a[j], i += 2, j++;

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
        if (b[i - 1] > b[i] and b[i] < b[i + 1])
            ans++;

    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << b[i] << " \n"[i == n - 1];
    
    return 0;
}