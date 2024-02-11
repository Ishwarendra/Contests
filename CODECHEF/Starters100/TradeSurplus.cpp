#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<int, 2> a{}, b{};
    std::cin >> a[0] >> a[1] >> b[0] >> b[1];  

    auto ans = a[0] + b[0] - a[1] - b[1];
    ans = -ans;
    std::cout << (ans > 0 ? "YES\n" : "NO\n");
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