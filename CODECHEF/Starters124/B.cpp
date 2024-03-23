#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int l, r;
    std::cin >> l >> r;

    if ((r - l + 1) % 2 and l % 2 == 0)  
    {
        std::cout << "-1\n";
        return;
    }

    int n = r - l + 1;
    if (n == 1)
    {
        std::cout << (l == 1 ? 1 : -1) << "\n";
        return;
    }

    std::vector<int> a(n);
    std::iota(std::begin(a), std::end(a), l);

    for (int i = 0; i + (n % 2 ? 3 : 0) < n; i += 2)
        std::swap(a[i], a[i + 1]);
    
    if (n % 2)
    {
        a[n - 3] = r - 1;
        a[n - 2] = r;
        a[n - 1] = r - 2;
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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