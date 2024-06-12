#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, q;
    std::cin >> n >> k >> q;
    
    std::vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++)
        std::cin >> a[i];
    for (int i = 1; i <= k; i++)
        std::cin >> b[i];
    
    while (q--)
    {
        int d;
        std::cin >> d;
        
        auto id = std::lower_bound(std::begin(a), std::end(a), d) - std::begin(a);
        if (a[id] == d)
        {
            std::cout << b[id] << " \n"[q == 0];
            continue;
        }
        
        std::cout << b[id - 1] + (1LL * (d - a[id - 1]) * (b[id] - b[id - 1])) / (a[id] - a[id - 1]) << " \n"[q == 0];
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