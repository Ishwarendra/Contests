#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a;
    std::cin >> a;

    if (a % 14 == 0)  
        std::cout << "Alice\n";
    else if (a % 9 == 0 and a % 2)
        std::cout << "Bob\n";
    else
        std::cout << "Charlie\n";
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