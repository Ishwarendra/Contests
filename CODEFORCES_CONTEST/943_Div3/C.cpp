#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> x(n - 1);
    for (int i = 0; i < n - 1; i++) 
        std::cin >> x[i];
    
    std::vector<int> a(n);
    a.back() = 1e9;
    
    for (int i = n - 2; i >= 0; i--)
        a[i] = a[i + 1] - x[i];
    
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
    
    for (int i = 1; i < n; i++)
        assert((a[i] % a[i - 1]) == x[i - 1]);
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