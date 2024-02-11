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

    std::set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        s.emplace(x);
    }

    int ans = *std::begin(s);
    while (s.count(ans))
        ans++;

    std::cout << ans;
    
    return 0;
}