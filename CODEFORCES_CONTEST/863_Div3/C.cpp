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

    std::vector<int> b(n);
    for (int i = 1; i < n; i++)  
        std::cin >> b[i];

    std::vector<int> a(n);
    a.front() = b[1];
    a.back() = b.back();

    for (int i = 1; i < n - 1; i++)
        a[i] = std::min(b[i], b[i + 1]);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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