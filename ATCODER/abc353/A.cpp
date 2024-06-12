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
    
    int n;
    std::cin >> n;
    
    int a;
    std::cin >> a;
    
    int ans = -1;
    for (int i = 2; i <= n; i++)
    {
        int x;
        std::cin >> x;
        
        if (x > a and ans == -1)
            ans = i;
    }
    
    std::cout << ans;
    
    return 0;
}