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
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > m)
        {
            std::cout << i;
            return 0;
        }
    }
    
    std::cout << n << '\n';
    
    return 0;
}