#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<int, 4> p{};
    for (int i = 0; i < 4; i++)  
        std::cin >> p[i];
    p[3] -= p[3] % 2;

    auto par = [&]()
    {
        for (int i = 1; i < 3; i++)
        {
            if (p[i - 1] % 2 != p[i] % 2)
                return -1;
        }

        return p[0] % 2;
    };

    int ans = 0;
    if (par() != 0)
    {
        ans += par() == 1;
        for (int i = 0; i < 3; i++)
            p[i] -= p[i] % 2;
    }

    for (int i = 0; i < 3; i++)
        ans += p[i] / 2;

    ans += p[3] / 2;
    std::cout << ans << '\n';
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