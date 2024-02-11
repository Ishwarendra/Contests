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
    
    int n;
    std::cin >> n;

    i64 ans = 0;
    for (int i = 2; i <= n - 1; i++)
        ans += 1LL * i * (i + 1);

    std::cout << ans;
    
    return 0;
}