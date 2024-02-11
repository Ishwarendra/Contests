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

    for (int i = 2; i <= n; i += 2)  
        std::cout << i << " ";
    for (int i = n - (n % 2 == 0); i >= 1; i -= 2)
        std::cout << i << " \n"[i == 1];
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