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
    
    int n, l;
    std::cin >> n >> l;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        ans += x >= l;
    }

    std::cout << ans;
    
    return 0;
}