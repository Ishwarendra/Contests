#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, sx, sy, d;
    std::cin >> n >> m >> sx >> sy >> d;

    int top = sx - d;
    int left = sy - d;
    int right = sy + d;
    int bottom = sx + d;

    if (top <= 1 and left <= 1)  
        std::cout << "-1\n";
    else if (bottom >= n and right >= m)
        std::cout << "-1\n";
    else if ((left <= 1 and right >= m) or (top <= 1 and bottom >= n))
        std::cout << "-1\n";
    else
        std::cout << n + m - 2 << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}