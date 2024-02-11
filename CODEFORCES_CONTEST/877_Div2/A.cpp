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

    int max = 0;
    int min = 1e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        max = std::max(max, x);
        min = std::min(min, x);
    }

    if (min < 0)
        std::cout << min << "\n";
    else
        std::cout << max << "\n";   
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