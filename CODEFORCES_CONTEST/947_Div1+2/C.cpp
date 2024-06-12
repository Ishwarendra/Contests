#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    int max = 0;
    for (int i = 0; i < n - 1; i++)
        max = std::max(max, std::min(a[i], a[i + 1]));
    for (int i = 0; i < n - 2; i++)
    {
        std::array<int, 3> b { a[i], a[i + 1], a[i + 2] };
        std::sort(std::begin(b), std::end(b));
        
        max = std::max(max, b[1]);
    }
    
    std::cout << max << "\n";
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