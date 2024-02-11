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
    
    int n, s, k;
    std::cin >> n >> s >> k;

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        std::cin >> p >> q;

        ans += p * q;
    }

    std::cout << ans + (ans < s) * k;
    
    return 0;
}