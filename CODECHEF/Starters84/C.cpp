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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int z = a.back() + a[n - 2];

    std::vector<int> b(n);
    for (int i = 0, j = n - 1, pos = 0; i <= j; i++, j--)
    {
        b[pos++] = a[j];
        if (pos < n)
            b[pos++] = a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] + b[i + 1] >= z)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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