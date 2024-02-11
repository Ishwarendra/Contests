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

    std::vector pos(n, 0);
    std::vector a(n, 0);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    int max = n - 1;
    for (int i = std::min(pos[0], pos[1]) + 1; i < std::max(pos[0], pos[1]); i++)
    {
        std::cout << pos[max] + 1 << " " << i + 1 << "\n";
        return;
    }

    if (pos[max] < std::min(pos[0], pos[1]))
        std::cout << pos[max] + 1 << " " << std::min(pos[0], pos[1]) + 1 << "\n";
    else 
        std::cout << pos[max] + 1 << " " << std::max(pos[0], pos[1]) + 1 << "\n";
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