#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 get(int r)
{
    i64 ans = 0;
    for (int x = 1; x <= r; x++)
    {
        int left = 1, right = r;
        int y = 0;
        
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (1LL * mid * mid < 1LL * r * r - 1LL * x * x)
                y = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        
        ans += y;
    }
    
    return ans * 4;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--)
    {
        int r;
        std::cin >> r;
        
        std::cout << get(r + 1) - get(r) + 4 << "\n";
    }
    
    return 0;
}