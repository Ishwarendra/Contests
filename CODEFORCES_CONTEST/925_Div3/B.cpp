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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 extra = 0;
    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL) / n;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= sum)
            extra += a[i] - sum;
        else if (a[i] + extra >= sum)
            extra -= sum - a[i];
        else
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

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}