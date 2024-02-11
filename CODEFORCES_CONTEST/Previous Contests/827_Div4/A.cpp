#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<int, 3> a;
    for (int i = 0; i < 3; i++)  
        std::cin >> a[i];
    std::sort(std::begin(a), std::end(a));

    if (a[0] + a[1] == a[2])
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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