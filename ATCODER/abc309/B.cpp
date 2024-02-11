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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto rotate = [&]()
    {
        auto b = a;
        b[0][0] = a[1][0];
        for (int i = 1; i < n; i++)
            b[0][i] = a[0][i - 1];
        for (int i = 1; i < n; i++)
            b[i][n - 1] = a[i - 1][n - 1];
        for (int i = n - 2; i >= 0; i--)
            b[n - 1][i] = a[n - 1][i + 1];
        for (int i = n - 2; i >= 0; i--)
            b[i][0] = a[i + 1][0];
        a = b;
    };

    rotate();
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\n";
    
    return 0;
}