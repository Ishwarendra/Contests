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

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    int ans = 0;
    for (auto [num, f] : m)
        ans += f / 2;
    std::cout << ans;
    
    return 0;
}