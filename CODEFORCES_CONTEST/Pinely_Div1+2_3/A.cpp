#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::array<int, 2> neg{}, pos{};
    for (int i = 0; i < n; i++)  
    {
        int x, y;
        std::cin >> x >> y;

        if (x < 0)
            neg[0] = 1;
        if (y < 0)
            neg[1] = 1;
        if (x > 0)
            pos[0] = 1;
        if (y > 0)
            pos[1] = 1;
    }

    if (neg[0] == neg[1] and pos[0] == pos[1] and neg[0] == 1 and pos[0] == 1)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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