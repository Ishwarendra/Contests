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
    
    i64 k, sx, sy, tx, ty;
    std::cin >> k >> sx >> sy >> tx >> ty;
    
    if (tx < sx)
        tx = sx + (sx - tx);
    if (ty < sy)
        ty = sy + (sy - ty);
    
    if (k == 1)
    {
        std::cout << std::abs(sx - tx) + std::abs(sy - ty);
        return 0;
    }
    
    auto onLarge = [&](i64 x, i64 y)
    {
        i64 s = (x / k) + (y / k);
        return s % 2 == 1;
    };
    
    auto get = [&](i64 x, i64 y) -> std::pair<i64, i64>
    {
        i64 xx = x % k;
        i64 yy = y % k;
        return { xx, yy };  
    };
    
    i64 large = std::max((tx - sx) / k, (ty - sy) / k);
    i64 ans = 2 * large - 2;
    
    auto [x1, y1] = get(sx, sy);
    ans += k - std::max(x1, y1);
    
    auto [x2, y2] = get(tx, ty);
    ans += k - std::max(x2, y2);
    
    std::cout << ans << "\n";
    
    return 0;
}