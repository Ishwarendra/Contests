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

    int best = -1, quality = -1;
    for (int i = 0; i < n; i++)  
    {
        int a, b;
        std::cin >> a >> b;

        if (a <= 10 and quality < b)
            quality = b, best = i + 1;
    }

    std::cout << best << "\n";
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