#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> b;
    for (int i = 0; i < n - k; i++)
        b.emplace_back(a[i]);
    for (int i = std::max(n - k, k); i < n; i++)
        b.emplace_back(a[i]);

    std::sort(std::rbegin(b), std::rend(b));

    for (int i = 0; i < n - k; i++)
        a[i] = b.back(), b.pop_back();
    for (int i = std::max(n - k, k); i < n; i++)
        a[i] = b.back(), b.pop_back();

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