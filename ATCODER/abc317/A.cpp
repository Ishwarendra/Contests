#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, h, x;
    std::cin >> n >> h >> x;

    std::array<int, 2> ans{1000, 1000};
    for (int i = 0; i < n; i++) 
    {
        int p;
        std::cin >> p;
        if (h + p >= x)
            ans = std::min(ans, std::array{p, i + 1});
    }

    std::cout << ans[1];
    
    return 0;
}