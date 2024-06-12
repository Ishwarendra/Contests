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
    
    int n, k;
    std::cin >> n >> k;
    
    int s = 0, ans = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        
        if (s + a > k)
            ans++, s = a;
        else
            s += a;
    }
    
    std::cout << ans;
    
    return 0;
}