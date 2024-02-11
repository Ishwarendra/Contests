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

    int ans = 1e9;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            std::cout << "0\n";
            return;
        }

        ans = std::min(ans, a[i] - a[i - 1]);
    }
    
    std::cout << ans / 2 + 1 << "\n";
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