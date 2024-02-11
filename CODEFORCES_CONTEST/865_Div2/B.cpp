#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    int max = 2 * n, min = n;
    a[0] = max--;
    b.back() = max--;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 and a[i] == 0)
            a[i] = max--;
        if (i % 2 and b[i] == 0)
            b[i] = max--;
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 and b[i] == 0)
            b[i] = min--;
        if (i % 2 != 0 and a[i] == 0)
            a[i] = min--;
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        std::cout << b[i] << " \n"[i == n - 1];
}   

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}   