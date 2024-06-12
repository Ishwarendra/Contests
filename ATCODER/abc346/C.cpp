#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        s.emplace(x);
    }

    i64 ans = 1LL * k * (k + 1) / 2;
    for (auto x : s)
    {
        if (1 <= x and x <= k)
            ans -= x;
    }

    std::cout << ans;
    
    return 0;
}