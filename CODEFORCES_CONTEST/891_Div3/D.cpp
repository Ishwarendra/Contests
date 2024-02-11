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

    int max = -2e9;
    for (int i = 0; i < n; i++)
        max = std::max(max, a[i] - b[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += a[i] - b[i] == max;

    std::cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        if (a[i] - b[i] == max)
            std::cout << i + 1 << " ";
    }
    
    std::cout << "\n";
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