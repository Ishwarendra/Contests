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
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::sort(std::begin(a), std::end(a));
    std::sort(std::rbegin(b), std::rend(b));

    for (int i = 0; i < n; i++)
    {
        if (a[i] + b[i] != a[0] + b[0])
        {
            std::cout << "-1\n";
            return;
        }
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

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}