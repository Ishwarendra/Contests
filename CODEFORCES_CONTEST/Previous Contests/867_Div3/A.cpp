#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        a[i] += i;
    }
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::array<int, 2> best{-1, 101};   
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= t)
            best = std::max(best, std::array {b[i], i + 1});
    }

    if (best[0] == -1)
        best[1] = -1;

    std::cout << best[1] << "\n";
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