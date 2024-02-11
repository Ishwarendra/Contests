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

    int ans = 0;
    for (int i = 0; i < n; i++)   
    {
        int a;
        std::cin >> a;
        ans += a - 1 == i;  
    }

    std::cout << (ans + 1) / 2 << "\n";
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