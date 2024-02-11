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
    
    int n, a, b;
    std::cin >> n >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        if (c == a + b)
            ans = i + 1;
    }

    std::cout << ans;
    
    return 0;
}