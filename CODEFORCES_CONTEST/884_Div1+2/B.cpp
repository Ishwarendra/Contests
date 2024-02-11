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

    if (n == 1)
        std::cout << "1\n";
    else if (n == 2)
        std::cout << "2 1\n";
    else
    {
        std::vector<int> a(n);
        a[n / 2] = 1;
        int i = n / 2 - 1, j = n / 2 + 1;
        a[0] = 2, a[n - 1] = 3;

        int cur = 4;
        while (i > 0)
            a[i--] = cur++;
        while (j < n - 1)
            a[j++] = cur++;

        for (int i = 0; i < n; i++)
            std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}